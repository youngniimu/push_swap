/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:22:32 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 17:22:32 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_ra(t_data *data)
{
	t_list *temp;

	if (ft_lstlen(data->stack_a) == 2)	
	{
		data->double_move = 1;
		execute_sa(data);
		data->double_move = 0;
	}
	else if (ft_lstlen(data->stack_a) > 2)
	{
		temp = data->stack_a;
		data->stack_a = temp->next;
		data->stack_a_tail->next = temp;
		data->stack_a_tail = temp;
		data->stack_a_tail->next = NULL;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("ra\n");
	return(0);
}