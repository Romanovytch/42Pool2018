/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 02:34:41 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:43:30 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	t_list	*max;
	void	*swap;
	int		swapped;

	swapped = 1;
	max = NULL;
	if (begin_list == NULL)
		return ;
	while (swapped)
	{
		swapped = 0;
		tmp = begin_list;
		while (tmp->next != max)
		{
			swapped = 1;
			swap = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = swap;
			tmp = tmp->next;
		}
		max = tmp;
	}
}
