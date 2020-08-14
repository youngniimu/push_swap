/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:53:35 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 15:53:35 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMMANDS_
# define _COMMANDS_

// # include "../checker/include/checker.h"
// # include "../push_swap/include/push_swap.h"

typedef struct		s_content
{
	int				value;
	int				median; //is the number belove or above median
}

typedef struct		s_data
{
	t_list			*stack_a;
	t_list			*stack_a_tail;
	t_list			*stack_b;
	t_list			*stack_b_tail;
	
	char			*command;
	int				err;
	int				read;
	int				in_order;
}					t_data;

// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
// 		is only one or no elements).
int		execute_sa(t_data *data);
// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
// 		is only one or no elements).
int		execute_sb(t_data *data);
// ss : sa and sb at the same time.
int		execute_ss(t_data *data);
// pa : push a - take the first element at the top of b and put it at the top of a. Do
// 		nothing if b is empty.
int		execute_pa(t_data *data);
// pb : push b - take the first element at the top of a and put it at the top of b. Do
// 		nothing if a is empty.
int		execute_pb(t_data *data);
// ra : rotate a - shift up all elements of stack a by 1. The first element becomes
// 		the last one.
int		execute_ra(t_data *data);
// rb : rotate b - shift up all elements of stack b by 1. The first element becomes
// 		the last one.
int		execute_rb(t_data *data);
// rr : ra and rb at the same time.
int		execute_rr(t_data *data);
// rra : 	reverse rotate a - shift down all elements of stack a by 1. The last element
// 			becomes the first one.
int		execute_rra(t_data *data);
// rrb : 	reverse rotate b - shift down all elements of stack b by 1. The last element
// 			becomes the first one.
int		execute_rrb(t_data *data);
// rrr : 	rra and rrb at the same time.
int		execute_rrr(t_data *data);

void	ft_read_input(char *av, t_data *data);

#endif