/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:51:46 by thalme            #+#    #+#             */
/*   Updated: 2020/09/01 14:51:47 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_count_stack_a(t_list *elem, int index, int value, int prev_val)
{
	index = 0;
	while (elem)
	{
		if (((t_elem*)elem->content)->index > value && prev_val < value)
			break ;
		prev_val = ((t_elem*)elem->content)->index;
		index++;
		elem = elem->next;
	}
	return (index);
}

int			ft_count_moves(t_data *data, int value, int index)
{
	int		moves;
	int		move_down;
	int		dir;
	int		previous_a_value;

	move_down = ft_lstlen(data->stack_b) - index;
	moves = (index < move_down) ? index : move_down;
	dir = (index < move_down) ? TOP : BOTTOM;
	previous_a_value = ((t_elem*)data->stack_a_tail->content)->index;
	index = ft_count_stack_a(data->stack_a, index, value, previous_a_value);
	move_down = ft_lstlen(data->stack_a) - index;
	moves += (index < move_down) ? index : move_down;
	dir += (index < move_down) ? TOP : BOTTOM;
	if (dir == TOP + TOP)
		moves = ft_abs(moves - (index < (moves - index)
		? index : moves - index));
	else if (dir == BOTTOM + BOTTOM)
		moves = ft_abs(moves - (move_down < (moves - move_down)
		? move_down : moves - move_down));
	return (moves);
}
