/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:10:44 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:03:28 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	tmp = *begin_list1;
	if (tmp == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = begin_list2;
}
