/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:22:32 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 17:22:32 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/include/checker.h"
#include "shared_src.h"

int		execute_ra(t_data *data)
{
	t_list *temp;

	if (ft_lstlen(data->stack_a) > 1)
	{
		temp = data->stack_a;
		data->stack_a = temp->next;
		data->stack_a_tail->next = temp;
		temp->next = NULL;
		data->stack_a_tail = temp;
	}
	return(0);
}