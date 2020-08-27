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

static void ft_next_move(char *command, t_data *data)
{
	printf("%s\n", command);
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

int			ft_keyboard_bindings(int button, t_data *data)
{
	printf("%d\n", button);
	if (button == 53)
		exit(1);
	if (button == 124)
	{
		ft_next_move(data->commands[data->command_index], data);
		data->command_index++;
		ft_visualize_stacks(data);
	}
	button == 124 ? ft_visualize_stacks(data) : NULL;
	return (0);
}

void		ft_visualize_stacks(t_data *data)
{
	t_list *a;
	t_list *b;
	int x;
	int y;

	a = data->stack_a;
	b = data->stack_b;
	x = 10;
	y = 0;

	while (a)
	{
		y = ((t_elem*)a->content)->value;
		while (y >= 0)
			mlx_pixel_put(MLX, WIN, x, y--, 352987);
		x += 2;
		a = a->next;
	}
	x += 20;
	while (b)
	{
		y = ((t_elem*)a->content)->value;
		while (y >= 0)
			mlx_pixel_put(MLX, WIN, x, y--, 352987);
		x += 2;
		b = b->next;
	}
}

void		ft_start_visualizer(t_data *data)
{
	int i = 0;
	while(data->commands[i])
		printf("%s", data->commands[i++]);
	data->command_index = 0;
	data->visualizer = (t_vdata*)malloc(sizeof(t_vdata));
	MLX = mlx_init();
    WIN = mlx_new_window(MLX, 640, 360, "Push_swap Visualizer");
	ft_visualize_stacks(data);
	mlx_key_hook(WIN, &ft_keyboard_bindings, data);
    mlx_loop(MLX);
}