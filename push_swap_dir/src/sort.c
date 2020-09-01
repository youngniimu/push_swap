/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:31:43 by thalme            #+#    #+#             */
/*   Updated: 2020/08/24 16:31:44 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_rotate_final_a(t_data *data)
{
	t_list	*head;
	int		index;

	head = data->stack_a;
	index = 0;
	while (head)
	{
		if ((((t_elem*)head->content)->index) == 0)
			break ;
		head = head->next;
		index++;
	}
	if (index < (data->len - index))
		while (index--)
			execute_ra(data);
	else
	{
		index = ft_lstlen(data->stack_a) - index;
		while (index--)
			execute_rra(data);
	}
}

void		ft_split_stack(t_data *data)
{
	int i;

	i = -1;
	while (++i <= data->len)
		(CURRENT_A_INDEX <= data->median && CURRENT_A_INDEX != 0)
		? execute_pb(data) : execute_ra(data);
	i = -1;
	while (ft_lstlen(data->stack_a) != 2)
		(CURRENT_A_INDEX > data->median && CURRENT_A_INDEX != data->len &&
		CURRENT_A_INDEX != 0) ? execute_pb(data) : execute_ra(data);
	if (CURRENT_A_INDEX < NEXT_A_INDEX)
		execute_sa(data);
}

int			ft_find_cheapest_index(t_data *data)
{
	t_list	*head;
	int		index;
	int		cheapest_index;
	int		least_moves;
	int		temp;

	index = 0;
	least_moves = 999;
	cheapest_index = 0;
	head = data->stack_b;
	while (head)
	{
		temp = ft_count_moves(data, ((t_elem*)head->content)->index, index);
		if (temp < least_moves)
		{
			cheapest_index = index;
			least_moves = temp;
		}
		index++;
		head = head->next;
	}
	return (cheapest_index);
}

void		ft_sort_stack(t_data *data)
{
	int		cheapest_index;
	int		i;
	t_list	*temp;

	if (ft_lstlen(data->stack_a) == 5)
		ft_sort_five(data);
	else if (ft_lstlen(data->stack_a) <= 3)
		ft_sort_short(data);
	else
	{
		ft_split_stack(data);
		while (1)
		{
			i = 0;
			cheapest_index = ft_find_cheapest_index(data);
			temp = data->stack_b;
			while (i++ < cheapest_index)
				temp = temp->next;
			ft_execute_cheapest_move(data, ((t_elem*)temp->content)->index,
			cheapest_index);
			if (!data->stack_b)
				break ;
		}
		ft_rotate_final_a(data);
	}
}
