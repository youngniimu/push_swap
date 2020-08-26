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

static int			ft_validate_input(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!(ft_isdigit(str[i])) && str[i] != ' ')
			return(1);
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

void				ft_read_input(char *av, t_data *data)
{
	char		**split;
	t_list		*list;
	int i;

	i = 0;
	data->err = ft_validate_input(av);
	ft_handle_error(data);
	split = ft_strsplit(av, ' ');
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
		free(split[i++]);
	free(split);
	data->read = 1;
	data->len = i - 1;
	data->max = i;
	data->median = i / 2;
	data->first_quarter = i / 4;
	data->third_quarter = data->first_quarter + data->median;
}
