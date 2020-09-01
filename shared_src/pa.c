/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:22:32 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 17:22:32 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_pa(t_data *data)
{
	t_list *node;
	t_list *temp;

	if (data->stack_b != NULL)
	{
		node = ft_lstnew(data->stack_b->content, data->stack_b->content_size);
		ft_lstadd(&data->stack_a, node);
		temp = data->stack_b->next;
		ft_lstdelone(&data->stack_b, &del);
		data->stack_b = temp;
		data->stack_a_tail = data->stack_a_tail ? data->stack_a_tail : node;
	}
	if (data->program == PUSH_SWAP && !data->double_move)
		ft_putendl("pa");
	return (0);
}
