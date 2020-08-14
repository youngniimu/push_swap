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

#include "../checker/include/checker.h"
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
        {
            printf("DUPLICATE FOUND: %d\n",*((int*)temp->content));
			return (5);
        }
        temp = temp->next;
    }
	return (0);
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

void				ft_read_input(char *av, t_data *data)
{
	char		**split;
	t_list		*list;
	int i;

	i = 0;
	data->err = ft_validate_input(av);
	split = ft_strsplit(av, ' ');
	list = ft_lstnew(&(int){ ft_atoi(split[i]) }, sizeof(int*));
	// list = ft_lstnew(split[i], sizeof(char*));
	data->stack_a = list;
	i++;
	while(split[i] != NULL)
	{
		list->next = ft_lstnew(&(int){ ft_atoi(split[i]) }, sizeof(int*));
		// list->next = ft_lstnew(split[i], sizeof(char*));
		if (split[i + 1] == NULL)
			data->stack_a_tail = list->next;
		list = list->next;
		i++;
	}
	data->err = ft_check_duplicates(data->stack_a);
	i = 0;
	while(split[i] != NULL)
		free(split[i++]);
	free(split);
	ft_handle_error(data);
	data->read = 1;
}



// int				ft_read_input(char *av, t_data *data)
// {
// 	char		**split;
// 	int 		*pnb;
// 	t_list		*list;

// 	split = ft_strsplit(av, ' ');
// 	data->err = ft_validateinput(split);
// 	pnb = (int*)malloc(sizeof(int));
// 	*pnb = ft_atoi(*split);
// 	list = ft_lstnew(pnb, sizeof(int*));
// 	data->stack_a = list;
// 	split++;
// 	while(*split != NULL)
// 	{
// 		pnb = (int*)malloc(sizeof(int));
// 		*pnb = ft_atoi(*split);
// 		list->next = ft_lstnew(pnb, sizeof(int*));
// 		list = list->next;
// 		split++;
// 	}
// 	ft_lstiter(data->stack_a, &ft_print_data);
// 	return(0);
// }