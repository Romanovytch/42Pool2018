/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:06:16 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 23:51:57 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = (t_btree *)malloc(sizeof(t_btree));
	elem->item = item;
	elem->left = NULL;
	elem->right = NULL;
	return (elem);
}
