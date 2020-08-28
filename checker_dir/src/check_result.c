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

// static int ft_check_stack_order(t_list **elem)
// {
// 	if ((*elem)->next != NULL && *((int*)(*elem)->content) < *((int*)(*elem)->next->content))
// 	{
// 		if((*elem)->next != NULL)
// 			ft_check_stack_order(&(*elem)->next);
// 		return(1);
// 	}
// 	return(0);
// }

// static int ft_check_stacks(t_data *data)
// {
// 	if (data->stack_b)
// 		return (3);
// 	if (ft_lstlen(data->stack_a) == 1)
// 		data->in_order = 1;
// 	else
// 		data->in_order = ft_check_stack_order(&data->stack_a);
// 	return(0);
// }

void		ft_check_result(t_data *data)
{
	ft_check_order(data);
	data->in_order ? printf("OK\n") : printf("KO\n");
	exit(0);
}