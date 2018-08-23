/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:28:14 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 22:48:19 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	insert(t_list **begin_list, int index, int nb, t_flag id)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*elem;
	int		i;

	elem = ft_create_elem(0, nb, id);
	tmp = *begin_list;
	prev = NULL;
	i = 0;
	while (i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		++i;
	}
	prev->next = elem;
	elem->next = tmp;
}
