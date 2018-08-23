/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:24:49 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 02:01:18 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_index(t_list **begin_list, int index)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	i = 0;
	tmp = *begin_list;
	prev = NULL;
	while (i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		++i;
	}
	if (prev == NULL)
		*begin_list = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp);
}
