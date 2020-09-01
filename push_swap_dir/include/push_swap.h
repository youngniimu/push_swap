/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:55:36 by thalme            #+#    #+#             */
/*   Updated: 2020/08/12 13:55:36 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../../libprintf/include/ft_printf.h"
# include "../../shared_src/shared_src.h"

void		ft_sort_stack(t_data *data);
void		ft_indexed_stack(t_data *data);
void		ft_rotate_final_a(t_data *data);
void		ft_sort_five(t_data *data);
void		ft_sort_short(t_data *data);
void		ft_execute_cheapest_move(t_data *data, int value, int index);
int			ft_count_moves(t_data *data, int value, int index);

#endif
