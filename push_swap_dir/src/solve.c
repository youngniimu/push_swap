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

static void		ft_sort_three(t_data *data)
{
		ST > ND && ND < RD && ST < RD ? execute_sa(data) : 0;
		ST > ND && ND < RD && ST > RD ? execute_ra(data) : 0;
		ST < ND && ND > RD && ST > RD ? execute_rra(data) : 0;
		ST < ND && ND > RD && ST < RD ? execute_sa(data) & execute_ra(data) : 0;
		ST > ND && ND > RD ? execute_sa(data) & execute_rra(data) : 0;
}

static void		ft_sort_short(t_data *data)
{
	if (ft_lstlen(data->stack_a) == 2)
		CURRENT_A_INDEX == 1 && NEXT_A_INDEX == 0 ? execute_sa(data) : 0;
	else if (ft_lstlen(data->stack_a) == 3)
		ft_sort_three(data);
}
/*
** PUSH STACK A TO STACK B, FIRST NUMBER BELOW MEDIAN, THEN OVER MEDIAN, (NO MAX NO MIN)
*/
void		ft_split_stack(t_data *data)
{
	int i;

	i = -1;
	if (ft_lstlen(data->stack_a) == 5)
	{
		while (ft_lstlen(data->stack_a) != 2)
			(CURRENT_A_INDEX != data->len && CURRENT_A_INDEX != 0) ? execute_pb(data) : execute_ra(data);
	}
	else
	{
		while (++i <= data->len)
			(CURRENT_A_INDEX <= data->median && CURRENT_A_INDEX != 0) ? execute_pb(data) : execute_ra(data);
		i = -1;
		while (ft_lstlen(data->stack_a) != 2)
			(CURRENT_A_INDEX > data->median && CURRENT_A_INDEX != data->len && CURRENT_A_INDEX != 0) ? execute_pb(data) : execute_ra(data);
	}	
	if (CURRENT_A_INDEX < NEXT_A_INDEX)
		execute_sa(data);
}

/*
** COUNT MOVES FOR EVERY INDEX IN STACK B
*/
int			ft_count_moves(t_data *data, int value, int index)
{
	int moves;
	int move_down;
	t_list *head;
	int previous_a_value;
	int dir;

	move_down = ft_lstlen(data->stack_b) - index;
	moves = (index < move_down) ? index : move_down;
	dir = (index < move_down) ? TOP : BOTTOM;
	head = data->stack_a;
	previous_a_value = ((t_elem*)data->stack_a_tail->content)->index;
	index = 0;
	while (head)
	{
		if (((t_elem*)head->content)->index > value && previous_a_value < value)
			break;
		previous_a_value = ((t_elem*)head->content)->index;
		index++;
		head = head->next;
	}
	move_down = ft_lstlen(data->stack_a) - index;
	moves += (index < move_down) ? index : move_down;
	dir += (index < move_down) ? TOP : BOTTOM;
	if (dir == TOP + TOP)
		moves = ft_abs(moves - (index < (moves - index) ? index : moves - index));
	else if (dir == BOTTOM + BOTTOM)
		moves = ft_abs(moves - (move_down < (moves - move_down) ? move_down : moves - move_down));
	// printf("total moves:\t%d\n\n", moves);
	return (moves);
}

/*
** ITERATE THROUGH ALL UNITS IN B AND FIND THE "CHEAPEST INDEX"
*/

int		ft_find_cheapest_index(t_data *data)
{
	t_list *head;
	int index;
	int cheapest_index;
	int least_moves;
	int temp;

	index = 0;
	least_moves = 999;
	cheapest_index = 0;
	head = data->stack_b;
	while(head)
	{
		temp = ft_count_moves(data, ((t_elem*)head->content)->index, index); 
//		// printf("moves:%d\n", temp);
		//printf("current leastmoves:%d\n", least_moves);
		if (temp < least_moves)
		{
			cheapest_index = index;
			least_moves = temp;
		}
		//printf("index:%d\n\n", index);
		index++;
		head = head->next;
	}
	// printf("cheapest:%d\n\n", cheapest_index);
	return (cheapest_index);
}

/*
** MAKE BLUEPRINT FOR BEST MOVE COMBINATION AND EXECUTE IT
*/

void	ft_execute_cheapest_move(t_data *data, int value, int index)
{
	int move_down;
	t_list *head;
	int previous_value;
	t_move cheapest;

	head = data->stack_a;
	move_down = ft_lstlen(data->stack_b) - index;
	if (index < move_down)
	{
		cheapest.b_dir = TOP;
		cheapest.b_amount = index;
	}
	else
	{
		cheapest.b_dir = BOTTOM;
		cheapest.b_amount = move_down;
	}
	// FIND RIGHT A_STACK INDEX, INITIALIZE PREVIOUS_VALUE AS A_STACK_TAIL->INDEX
	previous_value = ((t_elem*)data->stack_a_tail->content)->index;
	index = 0;
	while (head)
	{
		if (((t_elem*)head->content)->index > value && previous_value < value)
			break;
		previous_value = ((t_elem*)head->content)->index;
		index++;
		head = head->next;
	}
	move_down = ft_lstlen(data->stack_a) - index;
	if (index < move_down)
	{
		cheapest.a_dir = TOP;
		cheapest.a_amount = index;
	}
	else
	{
		cheapest.a_dir = BOTTOM;
		cheapest.a_amount = move_down;
	}
	while(cheapest.a_dir == cheapest.b_dir && cheapest.a_amount > 0 && cheapest.b_amount > 0)
	{
		cheapest.a_dir == TOP ? execute_rr(data) : execute_rrr(data);
		cheapest.a_amount--;
		cheapest.b_amount--;
	}
	while(cheapest.a_amount > 0)
	{
		cheapest.a_dir == TOP ? execute_ra(data) : execute_rra(data);
		cheapest.a_amount--;
	}
	while(cheapest.b_amount > 0)
	{
		cheapest.b_dir == TOP ? execute_rb(data) : execute_rrb(data);
		cheapest.b_amount--;
	}
	execute_pa(data);
}

/*
** ALL NUMBERS IN STACK A IN ORDER, ROTATE UNTIL 0 ON TOP
*/

void ft_rotate_final_a(t_data *data)
{
	t_list *head;
	int index;

	head = data->stack_a;
	index = 0;
	while (head)
	{
		if ((((t_elem*)head->content)->index) == 0)
			break;
		head = head->next;
		index++;
	}
	// printf("lstlen%d\n", ft_lstlen(data->stack_a));
	// printf("index is %d\n", index);
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

void		ft_sort_stack(t_data *data)
{
	int cheapest_index;
	int i;

	if (ft_lstlen(data->stack_a) <= 3)
		ft_sort_short(data);
	else
	{
		ft_split_stack(data);
		t_list *temp;
		while (1)
		{
			i = 0;
			cheapest_index = ft_find_cheapest_index(data);
			temp = data->stack_b;
			while (i++ < cheapest_index)
				temp = temp->next;
			ft_execute_cheapest_move(data, ((t_elem*)temp->content)->index, cheapest_index);
			if (!data->stack_b)
				break ;
		}
		ft_rotate_final_a(data);
	}	
		// printf("STACK A\n");
		// ft_lstiter(data->stack_a, &ft_print_data);
		// printf("STACK B\n");
		// ft_lstiter(data->stack_b, &ft_print_data);
}