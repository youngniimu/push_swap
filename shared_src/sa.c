/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:53:40 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 15:53:42 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_sa(t_data *data)
{
	if (ft_lstlen(data->stack_a) > 1)
		ft_lstswap(data->stack_a, data->stack_a->next);
	if (data->program == PUSH_SWAP && !data->double_move)
		printf("sa\n");
	return (0);
}
