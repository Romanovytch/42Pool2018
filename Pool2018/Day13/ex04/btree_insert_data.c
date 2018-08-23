/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 21:48:00 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 22:49:55 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)())
{
	t_btree	*tree;

	tree = *root;
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, tree->item) < 0)
		btree_insert_data(&tree->left, item, cmpf);
	else
		btree_insert_data(&tree->right, item, cmpf);
}
