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

void		ft_print_data(t_list *elem)
{
	printf("%5d%5d\n", ((t_elem*)elem->content)->value, ((t_elem*)elem->content)->index);
}

void		ft_sort_stack(t_data *data)
{
	int i = 0;
	int toptofind = data->len - 1;
	// int bottomtofind = 1;
	// int index;
	while (i <= data->len) 
	{
		//push numbers under 'median' to b
		if (((t_elem*)data->stack_a->content)->index <= data->first_quarter && ((t_elem*)data->stack_a->content)->index != 0)
		{
			execute_pb(data);
			printf("pb\n");
		}
		else
		{
			execute_ra(data);
			printf("ra\n");
		}
		i++;
	}

	i = 0;
	while (i <= data->len - data->first_quarter) 
	{
		//push numbers over 'median' to b
		if (((t_elem*)data->stack_a->content)->index <= data->median && ((t_elem*)data->stack_a->content)->index > data->first_quarter && ((t_elem*)data->stack_a->content)->index != data->len)
		{
			execute_pb(data);
			printf("pb\n");
		}
		else
		{
			execute_ra(data);
			printf("ra\n");
		}
		i++;
	}

	i = 0;
	while (i <= data->len - data->median) 
	{
		//push numbers over 'median' to b
		if (((t_elem*)data->stack_a->content)->index <= data->third_quarter && ((t_elem*)data->stack_a->content)->index > data->median && ((t_elem*)data->stack_a->content)->index != data->len)
		{
			execute_pb(data);
			printf("pb\n");
		}
		else
		{
			execute_ra(data);
			printf("ra\n");
		}
		i++;
	}

	i = 0;
	while (i <= data->len - data->third_quarter) 
	{
		//push numbers over 'median' to b
		if (((t_elem*)data->stack_a->content)->index >= data->third_quarter && ((t_elem*)data->stack_a->content)->index != data->len)
		{
			execute_pb(data);
			printf("pb\n");
		}
		else
		{
			execute_ra(data);
			printf("ra\n");
		}
		i++;
	}
	if (((t_elem*)data->stack_a->content)->index < ((t_elem*)data->stack_a->next->content)->index)
	{
		execute_sa(data);
		printf("sa\n");
	}

	while (!data->in_order)
	{
		// index = ft_calculate_cheapest_move(data)
		if (((t_elem*)data->stack_b->content)->index == toptofind)
		{
			execute_pa(data);
			printf("pa\n");
			toptofind--;
		}
		else
		{
			execute_rb(data);
			printf("rb\n");
		}
		if (!ft_lstlen(data->stack_b))
		{	
			execute_rra(data);
			printf("rra\n");
			break ;
		}
	}
	

		printf("=======STACK A=========\n");
		ft_lstiter(data->stack_a, &ft_print_data);
		printf("=======STACK B=========\n");
		ft_lstiter(data->stack_b, &ft_print_data);

}