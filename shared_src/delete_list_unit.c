/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:05:54 by thalme            #+#    #+#             */
/*   Updated: 2020/08/25 15:05:54 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

void	del(void *content, size_t content_size)
{
	free((t_elem*)content);
	content_size = 0;
	// printf("content %s\n", (char*)content);
	// printf("content_size %zu\n", content_size);
}
