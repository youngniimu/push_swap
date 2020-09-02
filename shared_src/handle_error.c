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
				ft_putendl("Error: duplicate found.");
			if (data->err == ONLY_NUMBERS)
				ft_putendl("Error: input must contain only numbers.");
			if (data->err == INTEGER)
				ft_putendl("Error: input must contain only integer values.");
			if (data->err == NOINPUT)
				ft_putendl("Error: no input");
			if (data->err == INV_COMMAND)
				ft_putendl("Error: invalid command");
			exit(1);
		}
		ft_putendl("Error");
		exit(1);
	}
}
