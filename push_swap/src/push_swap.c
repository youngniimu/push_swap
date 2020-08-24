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

void		ft_print_data(t_list *elem)
{
	printf("%5d'\n", *((int*)elem->content));
}

void	ft_handle_error(t_data *data)
{
	if (data->err)
	{
		printf("Error.\n");
		exit(1);
	}
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
	return(data);
}

void ft_lstminmax(t_data *data)
{
	t_list *head;
	int min;
	int max;
	int len;

	min = 2147483647;
	max = -2147483648;

	len = ft_lstlen(data->stack_a);
	head = data->stack_a;
	while (head)
	{
		if (*((int*)head->content) < min)
			min = *((int*)head->content);
		if (*((int*)head->content) > max)
			max = *((int*)head->content);
		head = head->next;
	}
	printf("min %d\n", min);
	printf("max %d\n", max);
}

void ft_indexed_stack(t_data *data)
{
	ft_lstminmax(data);
	// data->stack_a_tail->next = data->stack_a
	// while

	// head = data->stack_a;
	// i = 1;
	// if (i == len)
	// 	break;
	// data->stack_a_tail->next = NULL;
}

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data();
	if (ac == 2)
	{
		ft_read_input(av[1], data);
		ft_indexed_stack(data);
	}
	// ft_lstiter(data->stack_a, &ft_print_data);
	// ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	return(0);
}