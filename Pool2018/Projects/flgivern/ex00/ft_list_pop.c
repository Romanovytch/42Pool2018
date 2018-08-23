/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:07:18 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/18 21:01:35 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	pop(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *begin_list;
	prev = NULL;
	if (*begin_list == NULL)
		return ;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	if (prev == NULL)
		*begin_list = NULL;
	else
		prev->next = NULL;
}
