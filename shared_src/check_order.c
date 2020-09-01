/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:34:04 by thalme            #+#    #+#             */
/*   Updated: 2020/08/28 12:34:17 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

static int	ft_check_stack_order(t_list *elem)
{
	while (elem->next)
	{
		if (((t_elem*)elem->content)->value
			> ((t_elem*)elem->next->content)->value)
			return (0);
		elem = elem->next;
	}
	return (1);
}

void		ft_check_order(t_data *data)
{
	if (data->stack_b)
		return ;
	if (ft_lstlen(data->stack_a) == 1)
		data->in_order = 1;
	else
		data->in_order = ft_check_stack_order(data->stack_a);
}
