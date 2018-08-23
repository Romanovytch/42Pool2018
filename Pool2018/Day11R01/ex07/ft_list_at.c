/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:28:57 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 23:36:18 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (begin_list == NULL)
		return (NULL);
	while (i < nbr && begin_list != NULL)
	{
		begin_list = begin_list->next;
		++i;
	}
	if (i == nbr)
		return (begin_list);
	return (NULL);
}
