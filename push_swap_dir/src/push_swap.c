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

int main(int ac, char **av)
{
	t_data	*data;

	data = ft_init_data(PUSH_SWAP);
	ft_read_input(ac, av, data);
	ft_indexed_stack(data);
	ft_check_order(data);
	if (!data->in_order)
		ft_sort_stack(data);
	ft_lstdel(&data->stack_a, &del);	//leaks
	free(data);							//leaks
	return(0);
}