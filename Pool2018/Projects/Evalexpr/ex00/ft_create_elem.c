/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 23:03:39 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/18 21:00:23 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(char token, int nb, t_flag id)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	elem->token = token;
	elem->nb = nb;
	elem->id = id;
	elem->next = NULL;
	return (elem);
}
