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

#include "../checker/include/checker.h"
#include "shared_src.h"

int		execute_rrb(t_data *data)
{
	t_list	*temp;
	t_list	*list;
	int 	len;

	len = ft_lstlen(data->stack_b);
	if (len > 1)
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
	return (0);
}