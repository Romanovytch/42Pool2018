/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:03:38 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 14:34:08 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	i = 0;
	if ((res = (int *)malloc(sizeof(int) * length)) == NULL)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		++i;
	}
	return (res);
}
