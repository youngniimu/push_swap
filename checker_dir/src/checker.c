/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:37:50 by thalme            #+#    #+#             */
/*   Updated: 2020/08/24 14:38:24 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void		visualizer(t_data *data)
{
	data->commands = (char**)malloc(sizeof(char*) * 1000);
	while (get_next_line(0, &data->command))
	{
		CURR_COMMAND = (char*)malloc(ft_strlen(data->command) + 1);
		CURR_COMMAND = ft_strcpy(CURR_COMMAND, data->command);
		data->command_index++;
		free(data->command);
	}
	data->commands[data->command_index] = NULL;
	ft_start_visualizer(data);
}

int				main(int ac, char **av)
{
	t_data		*data;

	if (ac == 1)
		return (0);
	data = ft_init_data(CHECKER);
	ft_read_input(ac, av, data);
	if (data->flag != VISUALIZER)
		while (1)
			ft_read_command(data);
	else
		visualizer(data);
	ft_lstdel(&data->stack_a, &del);
	free(data);
	return (0);
}
