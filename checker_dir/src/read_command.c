/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:27:15 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 14:27:15 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void handle_command(t_data *data)
{
	int err;

	err = 2;
	err *= !ft_strequ("sa", data->command) ? 1 : execute_sa(data); 
	err *= !ft_strequ("sb", data->command) ? 1 : execute_sb(data);
	err *= !ft_strequ("ss", data->command) ? 1 : execute_ss(data);
	err *= !ft_strequ("pa", data->command) ? 1 : execute_pa(data);
	err *= !ft_strequ("pb", data->command) ? 1 : execute_pb(data);
	err *= !ft_strequ("ra", data->command) ? 1 : execute_ra(data);
	err *= !ft_strequ("rb", data->command) ? 1 : execute_rb(data);
	err *= !ft_strequ("rr", data->command) ? 1 : execute_rr(data);
	err *= !ft_strequ("rra", data->command) ? 1 : execute_rra(data);
	err *= !ft_strequ("rrb", data->command) ? 1 : execute_rrb(data);
	err *= !ft_strequ("rrr", data->command) ? 1 : execute_rrr(data);
	data->err = err;
}

void 	ft_read_command(t_data *data)
{
	if(get_next_line(0, &data->command))
	{
		handle_command(data);
		ft_handle_error(data);
		free(data->command);
		printf("=======STACK A=========\n");
		ft_lstiter(data->stack_a, &ft_print_data);
		printf("=======STACK B=========\n");
		ft_lstiter(data->stack_b, &ft_print_data);
	}
	else
		ft_check_result(data);
}