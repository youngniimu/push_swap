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

#ifndef SHARED_SRC_H
# define SHARED_SRC_H

# include "../libprintf/include/ft_printf.h"

# define CHECKER 0
# define PUSH_SWAP 1

# define TOP 1
# define BOTTOM -1

# define VISUALIZER 1
# define ERROR 2

# define DUPLICATE 1
# define ONLY_NUMBERS 2
# define INTEGER 3
# define NOINPUT 4

# define CURRENT_A_INDEX ((t_elem*)data->stack_a->content)->index
# define NEXT_A_INDEX ((t_elem*)data->stack_a->next->content)->index
# define CURRENT_B_INDEX ((t_elem*)data->stack_b->content)->index
# define NEXT_B_INDEX ((t_elem*)data->stack_b->next->content)->index
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
	long			value;
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

int					execute_sa(t_data *data);
int					execute_sb(t_data *data);
int					execute_ss(t_data *data);
int					execute_pa(t_data *data);
int					execute_pb(t_data *data);
int					execute_ra(t_data *data);
int					execute_rb(t_data *data);
int					execute_rr(t_data *data);
int					execute_rra(t_data *data);
int					execute_rrb(t_data *data);
int					execute_rrr(t_data *data);

void				ft_read_input(int ac, char **av, t_data *data);
void				ft_handle_error(t_data *data);
void				ft_print_data(t_list *elem);
void				ft_check_order(t_data *data);
void				del(void *content, size_t content_size);

int					ft_check_duplicates(t_list *head);

t_data				*ft_init_data(int program);
int					ft_check_max_int(t_list *elem);
int					ft_validate_input(char **tab);

#endif
