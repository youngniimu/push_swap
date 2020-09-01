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

static void visualizer(t_data *data)
{
	data->commands = (char**)malloc(sizeof(char*) * 1000);
	while(get_next_line(0, &data->command))
	{
		data->commands[data->command_index] = (char*)malloc(sizeof(char) * ft_strlen(data->command) + 1);
		data->commands[data->command_index] = ft_strcpy(data->commands[data->command_index], data->command);
		data->command_index++;
		free(data->command);
	}
	data->commands[data->command_index] = NULL;
	ft_start_visualizer(data);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return(0);
	data = ft_init_data(CHECKER);
	ft_read_input(ac, av, data);
	if (data->flag != VISUALIZER)
		while(1)
			ft_read_command(data);
	else
		visualizer(data);
	ft_lstiter(data->stack_a, &ft_print_data);
	ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	return(0);
}
