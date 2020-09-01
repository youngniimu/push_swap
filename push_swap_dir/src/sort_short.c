/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:46:09 by thalme            #+#    #+#             */
/*   Updated: 2020/09/01 09:46:10 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		ft_sort_three(t_data *data)
{
	A_ST > A_ND && A_ND < A_RD && A_ST < A_RD ? execute_sa(data) : 0;
	A_ST > A_ND && A_ND < A_RD && A_ST > A_RD ? execute_ra(data) : 0;
	A_ST < A_ND && A_ND > A_RD && A_ST > A_RD ? execute_rra(data) : 0;
	A_ST < A_ND && A_ND > A_RD && A_ST < A_RD ? execute_sa(data) & execute_ra(data) : 0;
	A_ST > A_ND && A_ND > A_RD ? execute_sa(data) & execute_rra(data) : 0;
}

void		ft_sort_short(t_data *data)
{
	if (ft_lstlen(data->stack_a) == 2)
		CURRENT_A_INDEX == 1 && NEXT_A_INDEX == 0 ? execute_sa(data) : 0;
	else if (ft_lstlen(data->stack_a) == 3)
		ft_sort_three(data);
}

void		ft_sort_five(t_data *data)
{
	while (ft_lstlen(data->stack_a) != 2)
			(CURRENT_A_INDEX != data->len && CURRENT_A_INDEX != 0) ? execute_pb(data) : execute_ra(data);
	if (CURRENT_A_INDEX < NEXT_A_INDEX)
		execute_sa(data);
	B_ST < B_ND && B_ND > B_RD && B_ST > B_RD ? execute_sb(data) : 0;
	B_ST < B_ND && B_ND > B_RD && B_ST < B_RD ? execute_rb(data) : 0;
	B_ST > B_ND && B_ND < B_RD && B_ST < B_RD ? execute_rrb(data) : 0;
	B_ST > B_ND && B_ND < B_RD && B_ST > B_RD ? execute_sb(data) & execute_rb(data) : 0;
	B_ST < B_ND && B_ND < B_RD ? execute_sb(data) & execute_rrb(data) : 0;
	while (ft_lstlen(data->stack_a) != 5)
		execute_pa(data);
	ft_rotate_final_a(data);
}