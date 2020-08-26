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

int		main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data(CHECKER);
	ft_read_input(ac, av, data);
	while(1)
		ft_read_command(data);
	ft_lstiter(data->stack_a, &ft_print_data);
	ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	// while(1);
	return(0);
}
