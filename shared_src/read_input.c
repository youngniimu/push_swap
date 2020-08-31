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

static int			ft_check_duplicates(t_list *head)
{
	int count;
    t_list *temp;
    t_list *temp1;

    temp = head;
    while(temp != NULL)
    {
        temp1 = head;
        count = 0;
        while(temp1 != NULL)
        {
			if (*((int*)temp->content) == *((int*)temp1->content))
                count++;
            temp1=temp1->next;
        }
        if(count > 1)
			return (1);
        temp = temp->next;
    }
	return (0);
}

static int ft_check_max_int(t_list *elem)
{
	while (elem)
	{
		if (((t_elem*)elem->content)->value > MAX_INT)
			return (6);
		elem = elem->next;
	}
	return(0);
}

static int			ft_validate_input(char **tab)
{
	int i;
	int j;
	int sign;

	i = 0;
	while(tab[i])
	{	
		j = 0;
		sign = 0;
		while(tab[i][j])
		{
			if (tab[i][j] == '-')
				sign++;
			if ((!(ft_isdigit(tab[i][j])) && tab[i][j] != ' ' && tab[i][j] != '-')
				|| sign == 2)
				return(2);
			j++;
		}
		i++;
	}
	return(0);
}

t_elem				*make_elem(int content)
{
	t_elem *elem;

	elem = (t_elem*)malloc(sizeof(t_elem));
	if (elem == NULL)
		return(NULL);						//MALLOC
	elem->value = content;
	elem->index = 0;
	return (elem);
}

void			create_list(char **split, t_data *data)
{

	t_elem 		*temp;
	int 		i;
	t_list		*list;

	i = 0;
	temp = make_elem(ft_atoi(split[i]));
	list = ft_lstnew(temp, sizeof(t_elem*));
	free(temp);
	data->stack_a = list;
	i++;
	while(split[i] != NULL)
	{
		temp = make_elem(ft_atoi(split[i]));
		list->next = ft_lstnew(temp, sizeof(t_elem*));
		free(temp);
		if (split[i + 1] == NULL)
			data->stack_a_tail = list->next;
		list = list->next;
		i++;
	}
}

void				ft_check_flags(char *av, int *i, t_data *data)
{
	if (ft_strequ(av, "-v"))
	{
		data->flag = VISUALIZER;
		*i += 1;
	}
	else if (ft_strequ(av, "-e"))
	{
		data->flag = ERROR;
		*i += 1;
	}
}

void				ft_read_input(int ac, char **av, t_data *data)
{
	char		**split;
	int 		i;

	i = 1;
	ft_check_flags(av[i], &i, data);
	if (ac == 2 || (ac == 3 && data->flag == VISUALIZER))
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
	while(split[i] != NULL)
	{
		if (ac == 2)
			free(split[i]);
		i++;
	}
	if (ac == 2)		
		free(split);
	data->len = i - 1;
	data->median = i / 2;
}
