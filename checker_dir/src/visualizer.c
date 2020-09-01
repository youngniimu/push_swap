/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 09:41:30 by thalme            #+#    #+#             */
/*   Updated: 2020/08/27 09:41:31 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void			ft_print_stack(t_list *curr, t_data *data, int *x)
{
	int				i;
	int				y;

	while (curr)
	{
		i = 0;
		y = 340;
		while (i < ((t_elem*)curr->content)->value)
		{
			mlx_pixel_put(MLX, WIN, *x, y--, 0xFFFFFF);
			i++;
		}
		*x += 2;
		curr = curr->next;
	}
}

void				ft_visualize_stacks(t_data *data)
{
	t_list			*a;
	t_list			*b;
	int				x;

	a = data->stack_a;
	b = data->stack_b;
	x = 10;
	mlx_string_put(MLX, WIN, x, 340, 0xFFFFFF, "A");
	ft_print_stack(data->stack_a, data, &x);
	x += 2;
	mlx_string_put(MLX, WIN, x, 340, 0xFFFFFF, "B");
	ft_print_stack(data->stack_b, data, &x);
}

static void			ft_next_move(char *command, t_data *data)
{
	ft_strequ("sa", command) ? execute_sa(data) : 0;
	ft_strequ("sb", command) ? execute_sb(data) : 0;
	ft_strequ("ss", command) ? execute_ss(data) : 0;
	ft_strequ("pa", command) ? execute_pa(data) : 0;
	ft_strequ("pb", command) ? execute_pb(data) : 0;
	ft_strequ("ra", command) ? execute_ra(data) : 0;
	ft_strequ("rb", command) ? execute_rb(data) : 0;
	ft_strequ("rr", command) ? execute_rr(data) : 0;
	ft_strequ("rra", command) ? execute_rra(data) : 0;
	ft_strequ("rrb", command) ? execute_rrb(data) : 0;
	ft_strequ("rrr", command) ? execute_rrr(data) : 0;
}

int					ft_keyboard_bindings(int button, t_data *data)
{
	char			*nb;

	if (button == 53)
		exit(1);
	if (button == 124)
	{
		if (data->commands[data->command_index] != NULL)
		{
			mlx_clear_window(MLX, WIN);
			ft_next_move(data->commands[data->command_index], data);
			free(data->commands[data->command_index]);
			data->command_index++;
			nb = ft_itoa(data->command_index);
			mlx_string_put(MLX, WIN, 10, 100, 0xFFFFFF, nb);
			free(nb);
			ft_visualize_stacks(data);
		}
		else
			mlx_string_put(MLX, WIN, 10, 130, 0xFFFFFF, "OK");
	}
	return (0);
}

void				ft_start_visualizer(t_data *data)
{
	data->command_index = 0;
	data->visualizer = (t_mlx*)malloc(sizeof(t_mlx));
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, (data->len * 2) + 22, 360, "pocketSorter");
	ft_visualize_stacks(data);
	mlx_hook(WIN, 2, 0, &ft_keyboard_bindings, data);
	mlx_hook(WIN, 3, 0, &ft_keyboard_bindings, data);
	mlx_loop(MLX);
}
