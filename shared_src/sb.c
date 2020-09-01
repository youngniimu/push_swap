/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:57:52 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 16:57:53 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_sb(t_data *data)
{
	if (ft_lstlen(data->stack_b) > 1)
		ft_lstswap(data->stack_b, data->stack_b->next);
	if (data->program == PUSH_SWAP && !data->double_move)
		ft_putendl("sb");
	return (0);
}
