/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 09:51:25 by thalme            #+#    #+#             */
/*   Updated: 2020/08/14 09:51:26 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/include/checker.h"
#include "shared_src.h"

int		execute_rrr(t_data *data)
{
	execute_rra(data);
	execute_rrb(data);
	return(0);
}