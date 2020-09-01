/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:25:30 by thalme            #+#    #+#             */
/*   Updated: 2020/08/25 14:25:31 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

void	ft_handle_error(t_data *data)
{
	if (data->err)
	{
		if (data->flag == ERROR)
		{
			if (data->err == DUPLICATE)
				ft_printf("Error: duplicate found.\n");
			if (data->err == ONLY_NUMBERS)
				ft_printf("Error: input must contain only numbers.\n");
			if (data->err == INTEGER)
				ft_printf("Error: input must contain only integer values.\n");
			if (data->err == NOINPUT)
				ft_printf("Error: no input\n");
			exit(1);
		}
		ft_printf("Error\n");
		exit(1);
	}
}
