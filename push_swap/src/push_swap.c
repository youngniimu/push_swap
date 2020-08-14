/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:52:29 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 14:52:30 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_print_data(t_list *elem)
{
	printf("value:'%5d'\n", *((int*)elem->content));
}

void	ft_handle_error(t_data *data)
{
	if (data->err)
	{
		printf("Error.\n");
		exit(1);
	}
}


t_data *ft_init_data()
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
	return(data);
}

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data();
	if (ac == 2)
	{
		ft_read_input(av[1], data);
	}
	ft_lstiter(data->stack_a, &ft_print_data);
	// ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	return(0);
}