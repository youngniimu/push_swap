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
			return (5);
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

	i = 0;
	while(tab[i])
	{	
		j = 0;
		while(tab[i][j])
		{
			if (!(ft_isdigit(tab[i][j])) && tab[i][j] != ' ')
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}

t_elem				*make_elem(long content)
{
	t_elem *elem;

	elem = (t_elem*)malloc(sizeof(t_elem));
	elem->value = content;
	elem->index = 0;
	return (elem);
}

void				ft_read_input(int ac, char **av, t_data *data)
{
	char		**split;
	t_list		*list;
	int i;
	i = 1;
	if (ft_strequ(av[i], "-v"))
	{
		printf("flag on\n");
		data->flag = VISUALIZER;
		i++;
	}
	if (ac == 2 || (ac == 3 && data->flag == VISUALIZER))
		split = ft_strsplit(av[i], ' ');
	else
		split = &av[i];
	printf("%d\n", i);
	i = 0;
	data->err = ft_validate_input(&split[i]);
	ft_handle_error(data);
	list = ft_lstnew(make_elem(ft_atoi(split[i])), sizeof(t_elem*));
	data->stack_a = list;
	i++;
	while(split[i] != NULL)
	{
		list->next = ft_lstnew(make_elem(ft_atoi(split[i])), sizeof(t_elem*));
		if (split[i + 1] == NULL)
			data->stack_a_tail = list->next;
		list = list->next;
		i++;
	}
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
	data->read = 1;
	data->len = i - 1;
	data->max = i;
	data->median = i / 2;
	data->first_quarter = i / 4;
	data->third_quarter = data->first_quarter + data->median;
}
