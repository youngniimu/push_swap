/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:59:52 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 16:59:52 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int		execute_ss(t_data *data)
{
	data->double_move = 1;
	execute_sa(data);
	execute_sb(data);
	if (data->program == PUSH_SWAP)
		printf("ss\n");
	data->double_move = 0;
	return (0);
}
