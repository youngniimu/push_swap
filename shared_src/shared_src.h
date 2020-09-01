/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_src.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:53:35 by thalme            #+#    #+#             */
/*   Updated: 2020/08/13 15:53:35 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHARED_SRC_
# define _SHARED_SRC_

// # include "../checker/include/checker.h"
// # include "../push_swap/include/push_swap.h"

# include "../libprintf/include/ft_printf.h"

# define CHECKER 0
# define PUSH_SWAP 1
# define TOP 1
# define BOTTOM -1
# define VISUALIZER 1
# define ERROR 2
# define DUPLICATE 1
# define ONLY_NUMBERS 2
# define CURRENT_A_INDEX ((t_elem*)data->stack_a->content)->index
# define NEXT_A_INDEX ((t_elem*)data->stack_a->next->content)->index
# define CURRENT_B_INDEX ((t_elem*)data->stack_b->content)->index
# define NEXT_B_INDEX ((t_elem*)data->stack_b->next->content)->index
// # define THIRD_A_INDEX ((t_elem*)data->stack_a->next->next->content)->index
# define MLX data->visualizer->mlx
# define WIN data->visualizer->win

# define A_ST ((t_elem*)data->stack_a->content)->index
# define A_ND ((t_elem*)data->stack_a->next->content)->index
# define A_RD ((t_elem*)data->stack_a->next->next->content)->index

# define B_ST ((t_elem*)data->stack_b->content)->index
# define B_ND ((t_elem*)data->stack_b->next->content)->index
# define B_RD ((t_elem*)data->stack_b->next->next->content)->index


typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_move
{
	int				a_dir;
	int				a_amount;
	int				b_dir;
	int				b_amount;
}					t_move;

typedef struct		s_elem
{
	int				value;
	int				index;
}					t_elem;

typedef struct		s_data
{
	t_list			*stack_a;
	t_list			*stack_a_tail;
	t_list			*stack_b;
	t_list			*stack_b_tail;
	char			*command;
	int				err;
	int				in_order;
	int				median;
	int				len;
	int				program;
	int				double_move;
	int				flag;
	int				command_index;
	char			**commands;
	t_mlx			*visualizer;
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

void	ft_read_input(int ac, char **av, t_data *data);
void	ft_handle_error(t_data *data);
void	ft_print_data(t_list *elem);
void 	ft_check_order(t_data *data);
void 	del(void *content, size_t content_size);
t_data 	*ft_init_data(int program);

#endif