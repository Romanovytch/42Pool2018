/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_getindex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:21:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 01:24:26 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_getindex(t_list *list, t_list *elem)
{
	int	i;

	i = 0;
	while (list != elem)
	{
		list = list->next;
		++i;
	}
	return (i);
}
