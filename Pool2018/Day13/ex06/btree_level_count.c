/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 23:27:32 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 23:39:17 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	biggest(int l, int r)
{
	if (l > r)
		return (l);
	return (r);
}

int	btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	return (biggest(btree_level_count(root->left) + 1,
				btree_level_count(root->right) + 1));
}
