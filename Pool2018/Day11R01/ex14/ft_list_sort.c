/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:52:47 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:13:26 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*max;
	void	*swap;
	int		flag;

	flag = 1;
	max = NULL;
	while (flag == 1 && *begin_list != NULL)
	{
		flag = 0;
		tmp = *begin_list;
		while (tmp->next != max)
		{
			if (cmp(tmp->next->data, tmp->data) < 0)
			{
				swap = tmp->next->data;
				tmp->next->data = tmp->data;
				tmp->data = swap;
				flag = 1;
			}
			tmp = tmp->next;
		}
		max = tmp;
	}
}
