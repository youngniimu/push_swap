/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:22:32 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 17:22:32 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_pb(t_data *data)
{
	t_list *node;
	t_list *temp;

	if (data->stack_a != NULL)
	{
		node = ft_lstnew(data->stack_a->content, data->stack_a->content_size);
		ft_lstadd(&data->stack_b, node);
		temp = data->stack_a->next;
		ft_lstdelone(&data->stack_a, &del);
		data->stack_a = temp;
		data->stack_b_tail = data->stack_b_tail ? data->stack_b_tail : node;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("pb\n");
	return (0);
}
