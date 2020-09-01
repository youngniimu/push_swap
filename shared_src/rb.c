/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:22:32 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 17:22:32 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int			execute_rb(t_data *data)
{
	t_list	*temp;

	if (ft_lstlen(data->stack_b) == 2)
	{
		data->double_move = 1;
		execute_sb(data);
		data->double_move = 0;
	}
	else if (ft_lstlen(data->stack_b) > 2)
	{
		temp = data->stack_b;
		data->stack_b = temp->next;
		data->stack_b_tail->next = temp;
		data->stack_b_tail = temp;
		data->stack_b_tail->next = NULL;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("rb\n");
	return (0);
}
