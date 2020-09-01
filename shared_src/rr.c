/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:59:37 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 18:59:37 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_rr(t_data *data)
{
	data->double_move = 1;
	execute_ra(data);
	execute_rb(data);
	if (data->program == PUSH_SWAP)
		printf("rr\n");
	data->double_move = 0;
	return (0);
}
