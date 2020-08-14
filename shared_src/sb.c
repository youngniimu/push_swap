/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:57:52 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 16:57:53 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/include/checker.h"
#include "shared_src.h"

int		execute_sb(t_data *data)
{
	// printf("sb function\n");
	// if (data->stack_b || data->stack_b->next)
	// {
	// 	printf("swap b\n");
	// 	ft_lstswap(data->stack_b, data->stack_b->next);
	// }
	// else
	// {
	// 	printf("tried to swap b but no values\n");
	// }
	ft_lstswap(data->stack_b, data->stack_b->next);
	return (0);
}
