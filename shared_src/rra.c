/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:51:11 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 09:51:12 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_rra(t_data *data)
{
	t_list	*temp;
	t_list	*list;
	int 	len;
	int 	print;

	print = data->double_move;
	len = ft_lstlen(data->stack_a);
	if (len == 2)	
	{
		data->double_move = 1;
		execute_sa(data);
		if (!print)
			data->double_move = 0;
	}
	else if (len > 2)
	{
		temp = data->stack_a;
		data->stack_a = data->stack_a_tail;
		data->stack_a->next = temp;

		list = data->stack_a;
		while (len > 1)
		{
			list = list->next;
			len--;
		}
		data->stack_a_tail = list;
		data->stack_a_tail->next = NULL;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("rra\n");
	return (0);
}