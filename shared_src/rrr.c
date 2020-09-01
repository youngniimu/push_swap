/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:51:25 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 09:51:26 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_rrr(t_data *data)
{
	data->double_move = 1;
	execute_rra(data);
	execute_rrb(data);
	if (data->program == PUSH_SWAP)
		printf("rrr\n");
	data->double_move = 0;
	return (0);
}
