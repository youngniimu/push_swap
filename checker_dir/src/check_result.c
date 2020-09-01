/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:56:28 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 14:56:28 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void		ft_check_result(t_data *data)
{
	ft_check_order(data);
	data->in_order ? printf("OK\n") : printf("KO\n");
	exit(0);
}