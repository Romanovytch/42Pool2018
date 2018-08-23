/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:48:00 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 18:49:11 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;
	t_list	*tmp;

	current = *begin_list;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			tmp = current;
			if (current == *begin_list)
				*begin_list = next;
			else
				prev->next = next;
			prev = current;
			free(tmp);
		}
		prev = current;
		current = next;
	}
}
