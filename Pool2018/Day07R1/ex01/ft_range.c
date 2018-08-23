/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:43:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/06 16:29:03 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int				*tab;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = max - min;
	if (min >= max)
		return (NULL);
	if ((tab = (int *)malloc(sizeof(int) * (size))) == NULL)
		return (NULL);
	while (i < size)
		tab[i++] = min++;
	return (tab);
}
