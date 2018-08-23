/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:20:37 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:26:29 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*tmp;
	t_list	*prev;

	prev = NULL;
	tmp = *begin_list;
	while (tmp != NULL && tmp != elem)
	{
		if (cmp(elem->data, tmp->data) < 0)
		{
			if (prev == NULL)
				*begin_list = elem;
			else
				prev->next = elem;
			elem->next = tmp;
			return ;
		}
		else if (tmp->next == NULL)
			tmp->next = elem;
		prev = tmp;
		tmp = tmp->next;
	}
	if (*begin_list == NULL)
		*begin_list = elem;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*current;
	t_list	*next_elem;

	current = begin_list2;
	while (current != NULL)
	{
		next_elem = current->next;
		ft_sorted_list_insert(begin_list1, current, cmp);
		current = next_elem;
	}
}
