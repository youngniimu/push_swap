/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:33:27 by thalme            #+#    #+#             */
/*   Updated: 2020/08/25 14:33:27 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

void		ft_print_data(t_list *elem)
{
	printf("%10ld%10d\n", ((t_elem*)elem->content)->value, ((t_elem*)elem->content)->index);
}