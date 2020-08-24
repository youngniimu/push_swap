/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:52:29 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 14:52:30 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void		ft_print_data(t_list *elem)
// {
// 	printf("%5d%5d\n", ((t_elem*)elem->content)->value, ((t_elem*)elem->content)->index);
// }

void	ft_handle_error(t_data *data)
{
	if (data->err)
	{
		printf("Error.\n");
		exit(1);
	}
}

static void	del(void *content, size_t content_size)
{
	free((t_elem*)content);
	content_size = 0;
	// printf("content %s\n", (char*)content);
	// printf("content_size %zu\n", content_size);
}

t_data *ft_init_data()
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return(NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->stack_a_tail = NULL;
	data->stack_b_tail = NULL;
	data->command = NULL;
	data->err = 0;
	data->read = 0;
	data->in_order = 0;
	data->min = 0;
	data->max = 0;
	data->median = 0;
	data->first_quarter = 0;
	data->third_quarter = 0;
	data->len = 0;
	return(data);
}

// void ft_lstminmax(t_data *data)
// {
// 	t_list *head;
// 	int len;

// 	len = ft_lstlen(data->stack_a);
// 	head = data->stack_a;
// 	while (head)
// 	{
// 		if (*((int*)head->content) < data->min)
// 			data->min = *((int*)head->content);
// 		if (*((int*)head->content) > data->max)
// 			data->max = *((int*)head->content);
// 		head = head->next;
// 	}
// 	// printf("min %d\n", data->min);
// 	// printf("max %d\n", data->max);
// }

int *ft_sort_list(t_data *data)
{
	int *sorted;
	// int len;
	int i;
	int j;
	t_list *head;

	head = data->stack_a;
	// dalen = ft_lstlen(data->stack_a);
	sorted = (int*)malloc(sizeof(int) * data->len);
	i = 0;
	while(head)
	{
		sorted[i++] = ((t_elem*)head->content)->value;
		head = head->next;
	}
	i = 0;
	while(i < data->len)
	{
		j = i + 1;
		while(j < data->len)
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
	// int len;
	int i;

	// len = ft_lstlen(data->stack_a);
	sorted_list = ft_sort_list(data);
	head = data->stack_a;
	i = 0;
	while (head)
	{
		i = 0;
		while (sorted_list[i] != ((t_elem*)head->content)->value)
			i++;
		((t_elem*)head->content)->index = i;
		head = head->next;
	}
	// free sorted int list;
}

// void ft_indexed_stack(t_data *data)
// {
// 	// ft_lstminmax(data);
// 	ft_add_index_to_data(data);
// 	// data->stack_a_tail->next = data->stack_a
// 	// while

// 	// head = data->stack_a;
// 	// i = 1;
// 	// if (i == len)
// 	// 	break;
// 	// data->stack_a_tail->next = NULL;
// }

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data();
	if (ac == 2)
	{
		ft_read_input(av[1], data);
		ft_indexed_stack(data);
		ft_sort_stack(data);
	}
	// ft_lstiter(data->stack_a, &ft_print_data);
	ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	return(0);
}