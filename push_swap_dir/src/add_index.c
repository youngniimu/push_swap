/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:00:46 by thalme            #+#    #+#             */
/*   Updated: 2020/08/26 14:00:46 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int *ft_sort_list(t_data *data)
{
	int *sorted;
	int i;
	int j;
	t_list *head;

	head = data->stack_a;
	sorted = (int*)malloc(sizeof(int) * data->len + 1);
	i = 0;
	while(head)
	{
		sorted[i] = ((t_elem*)head->content)->value;
		head = head->next;
		i++;
	}
	i = 0;
	while(i < data->len)
	{
		j = i + 1;
		while(j <= data->len)
		{
			if (sorted[i] > sorted[j])
				ft_swap(&sorted[i], &sorted[j]);
			j++;
		}
		i++;
	}
	return(sorted);
}

void ft_indexed_stack(t_data *data)
{
	int *sorted_list;
	t_list *head;
	int i;

	sorted_list = ft_sort_list(data);
	head = data->stack_a;
	while (head)
	{
		i = -1;
		while (sorted_list[++i] != ((t_elem*)head->content)->value);
		((t_elem*)head->content)->index = i;
		head = head->next;
	}
	free(sorted_list);
}