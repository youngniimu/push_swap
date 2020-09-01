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

static int		*ft_make_int_tab(t_data *data)
{
	t_list		*head;
	int			*sorted;
	int			i;

	i = 0;
	head = data->stack_a;
	sorted = (int*)malloc(sizeof(int) * data->len + 1);
	while (head)
	{
		sorted[i] = ((t_elem*)head->content)->value;
		head = head->next;
		i++;
	}
	return (sorted);
}

static int		*ft_sort_list(t_data *data)
{
	int			*sorted;
	int			i;
	int			j;

	i = 0;
	sorted = ft_make_int_tab(data);
	while (i < data->len)
	{
		j = i + 1;
		while (j <= data->len)
		{
			if (sorted[i] > sorted[j])
				ft_swap(&sorted[i], &sorted[j]);
			j++;
		}
		i++;
	}
	return (sorted);
}

void			ft_indexed_stack(t_data *data)
{
	t_list		*head;
	int			*sorted_list;
	int			i;

	sorted_list = ft_sort_list(data);
	head = data->stack_a;
	while (head)
	{
		i = 0;
		while (sorted_list[i] != ((t_elem*)head->content)->value)
			i++;
		((t_elem*)head->content)->index = i;
		head = head->next;
	}
	free(sorted_list);
}
