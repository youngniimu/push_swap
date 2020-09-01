/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:10:59 by thalme            #+#    #+#             */
/*   Updated: 2020/08/12 15:10:59 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "mlx.h"

# include <stdlib.h>
# include "../../libprintf/include/ft_printf.h"
# include "../../shared_src/shared_src.h"

void		ft_handle_error(t_data *data);
void		ft_read_command(t_data *data);
void		ft_check_result(t_data *data);
void		ft_start_visualizer(t_data *data);
void		ft_print_stacks(t_list *elem);

#endif
