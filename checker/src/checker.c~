/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:37:50 by thalme            #+#    #+#             */
/*   Updated: 2020/08/12 14:37:50 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void		ft_print_data(t_list *elem)
{
	printf("value:'%5d'\n", *((int*)elem->content);
}

void	ft_handle_error(t_data *data)
{
	if (data->err)
	{
		printf("Error.\n");
		exit(1);
	}
}

void	del(void *content, size_t content_size)
{
	free((char*)content);
	content_size = 0;
	// printf("content %s\n", (char*)content);
	// printf("content_size %zu\n", content_size);
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

int		main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data();
	while (ac > 1)
	{
		if (!data->read)
			ft_read_input(av[1], data);
		else
			ft_read_command(data);
	}
	ft_lstiter(data->stack_a, &ft_print_data);
	ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	// while(1);
	return(0);
}