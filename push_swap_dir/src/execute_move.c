/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:15:27 by thalme            #+#    #+#             */
/*   Updated: 2020/09/01 14:15:28 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_exec(t_move cheapest, t_data *data)
{
	while (cheapest.a_dir == cheapest.b_dir &&
	cheapest.a_amount > 0 && cheapest.b_amount > 0)
	{
		cheapest.a_dir == TOP ? execute_rr(data) : execute_rrr(data);
		cheapest.a_amount--;
		cheapest.b_amount--;
	}
	while (cheapest.a_amount > 0)
	{
		cheapest.a_dir == TOP ? execute_ra(data) : execute_rra(data);
		cheapest.a_amount--;
	}
	while (cheapest.b_amount > 0)
	{
		cheapest.b_dir == TOP ? execute_rb(data) : execute_rrb(data);
		cheapest.b_amount--;
	}
	execute_pa(data);
}

static void	ft_set_amount(t_move *cheapest, int dir, int amount, char stack)
{
	if (stack == 'b')
	{
		cheapest->b_dir = dir;
		cheapest->b_amount = amount;
	}
	else
	{
		cheapest->a_dir = dir;
		cheapest->a_amount = amount;
	}
}

void		ft_execute_cheapest_move(t_data *data, int value, int index)
{
	t_list	*head;
	t_move	cheapest;
	int		previous_value;
	int		move_down;

	head = data->stack_a;
	move_down = ft_lstlen(data->stack_b) - index;
	index < move_down
	? ft_set_amount(&cheapest, TOP, index, 'b')
	: ft_set_amount(&cheapest, BOTTOM, move_down, 'b');
	previous_value = ((t_elem*)data->stack_a_tail->content)->index;
	index = 0;
	while (head)
	{
		if (((t_elem*)head->content)->index > value && previous_value < value)
			break ;
		previous_value = ((t_elem*)head->content)->index;
		index++;
		head = head->next;
	}
	move_down = ft_lstlen(data->stack_a) - index;
	index < move_down
	? ft_set_amount(&cheapest, TOP, index, 'a')
	: ft_set_amount(&cheapest, BOTTOM, move_down, 'a');
	ft_exec(cheapest, data);
}
