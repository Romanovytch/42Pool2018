/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 23:06:37 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/18 21:06:36 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	push(t_list **begin_list, char token, int nb, t_flag id)
{
	t_list	*new_elem;
	t_list	*tmp;

	tmp = *begin_list;
	new_elem = ft_create_elem(token, nb, id);
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
}
