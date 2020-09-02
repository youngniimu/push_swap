/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:19:43 by thalme            #+#    #+#             */
/*   Updated: 2020/08/12 15:19:43 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

t_elem				*make_elem(long content)
{
	t_elem *elem;

	elem = (t_elem*)malloc(sizeof(t_elem));
	if (elem == NULL)
		return (NULL);
	elem->value = content;
	elem->index = 0;
	return (elem);
}

void				create_list(char **split, t_data *data)
{
	t_elem			*temp;
	int				i;
	t_list			*list;

	if (!split[0])
	{
		data->err = 5;
		ft_handle_error(data);
	}
	i = 0;
	temp = make_elem(ft_atolong(split[i]));
	list = ft_lstnew(temp, sizeof(t_elem));
	free(temp);
	data->stack_a = list;
	i++;
	while (split[i] != NULL)
	{
		temp = make_elem(ft_atolong(split[i]));
		list->next = ft_lstnew(temp, sizeof(t_elem));
		free(temp);
		if (split[i + 1] == NULL)
			data->stack_a_tail = list->next;
		list = list->next;
		i++;
	}
}

void				ft_check_flags(char *av, int *i, t_data *data, int ac)
{
	if (ft_strequ(av, "-v"))
	{
		data->flag = VISUALIZER;
		*i += 1;
		if (ac == 2)
			exit(0);
	}
	else if (ft_strequ(av, "-e"))
	{
		data->flag = ERROR;
		*i += 1;
		if (ac == 2)
			exit(0);
	}
	if (av[0] == '\0')
		exit(0);
}

static void			ft_free_split(char **split, int ac, int *i)
{
	while (split[*i] != NULL)
	{
		if (ac == 2)
			free(split[*i]);
		*i += 1;
	}
	if (ac == 2)
		free(split);
}

void				ft_read_input(int ac, char **av, t_data *data)
{
	char		**split;
	int			i;

	i = 1;
	ft_check_flags(av[i], &i, data, ac);
	if (ac == 2 || (ac == 3 && data->flag))
		split = ft_strsplit(av[i], ' ');
	else
		split = &av[i];
	i = 0;
	data->err = ft_validate_input(&split[i]);
	ft_handle_error(data);
	create_list(&split[i], data);
	data->err = ft_check_duplicates(data->stack_a);
	ft_handle_error(data);
	data->err = ft_check_max_int(data->stack_a);
	ft_handle_error(data);
	i = 0;
	ft_free_split(split, ac, &i);
	data->len = i - 1;
	data->median = i / 2;
}
