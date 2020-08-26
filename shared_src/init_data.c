/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:10:48 by thalme            #+#    #+#             */
/*   Updated: 2020/08/26 11:10:48 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

t_data *ft_init_data(int program)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return(NULL);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->stack_a_tail = NULL;
	data->stack_b_tail = NULL;
	data->command = NULL;
	data->err = 0;
	data->read = 0;
	data->in_order = 0;
	data->min = 0;
	data->max = 0;
	data->median = 0;
	data->first_quarter = 0;
	data->third_quarter = 0;
	data->len = 0;
	data->double_move = 0;
	data->program = program;
	data->cheapest_move = program == PUSH_SWAP ? (t_move*)malloc(sizeof(t_move)) : NULL;
	return(data);
}