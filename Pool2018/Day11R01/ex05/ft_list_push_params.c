/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:50:43 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 23:30:20 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	while (i < ac)
	{
		push_front(&list, av[i]);
		++i;
	}
	return (list);
}
