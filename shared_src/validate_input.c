/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:43:07 by thalme            #+#    #+#             */
/*   Updated: 2020/09/01 12:43:09 by thalme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_src.h"

int			ft_check_duplicates(t_list *head)
{
	int		count;
	t_list	*temp;
	t_list	*temp1;

	temp = head;
	while (temp != NULL)
	{
		temp1 = head;
		count = 0;
		while (temp1 != NULL)
		{
			if (*((int*)temp->content) == *((int*)temp1->content))
				count++;
			temp1 = temp1->next;
		}
		if (count > 1)
			return (DUPLICATE);
		temp = temp->next;
	}
	return (0);
}

int			ft_check_max_int(t_list *elem)
{
	while (elem)
	{
		if (((t_elem*)elem->content)->value > MAX_INT)
			return (INTEGER);
		if (((t_elem*)elem->content)->value < MIN_INT)
			return (INTEGER);
		elem = elem->next;
	}
	return (0);
}

int			ft_validate_input(char **tab)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	while (tab[i])
	{
		j = 0;
		sign = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-')
				sign++;
			if ((!(ft_isdigit(tab[i][j]))
				&& tab[i][j] != ' ' && tab[i][j] != '-')
				|| sign == 2)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}
