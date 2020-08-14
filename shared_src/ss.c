/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:59:52 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 16:59:52 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker/include/checker.h"
#include "shared_src.h"

int		execute_ss(t_data *data)
{
	execute_sa(data);
	execute_sb(data);
	return (0);
}
