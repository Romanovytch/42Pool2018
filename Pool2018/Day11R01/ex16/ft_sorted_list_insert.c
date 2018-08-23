/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:52:47 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:42:48 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*new;

	prev = NULL;
	tmp = *begin_list;
	new = ft_create_elem(data);
	while (tmp != NULL && tmp != new)
	{
		if (cmp(data, tmp->data) < 0)
		{
			if (prev == NULL)
				*begin_list = new;
			else
				prev->next = new;
			new->next = tmp;
			return ;
		}
		else if (tmp->next == NULL)
			tmp->next = new;
		prev = tmp;
		tmp = tmp->next;
	}
	if (*begin_list == NULL)
		*begin_list = new;
}
