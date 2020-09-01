/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:51:19 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 09:51:20 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

static void		handle_special_case(t_data *data)
{
	int			print;

	print = data->double_move;
	data->double_move = 1;
	execute_sb(data);
	if (!print)
		data->double_move = 0;
}

int				execute_rrb(t_data *data)
{
	t_list		*temp;
	t_list		*list;
	int			len;

	len = ft_lstlen(data->stack_b);
	if (len == 2)
		handle_special_case(data);
	else if (len > 2)
	{
		temp = data->stack_b;
		data->stack_b = data->stack_b_tail;
		data->stack_b->next = temp;
		list = data->stack_b;
		while (len > 1)
		{
			list = list->next;
			len--;
		}
		data->stack_b_tail = list;
		data->stack_b_tail->next = NULL;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("rrb\n");
	return (0);
}
