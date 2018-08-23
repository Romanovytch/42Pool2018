/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:43:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 14:55:09 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	unsigned int		i;
	unsigned int		size;

	i = 0;
	size = (unsigned int)(max - min);
	if (min >= max)
	{
		*range = NULL;
		range = NULL;
		return (0);
	}
	if ((*range = (int *)malloc(sizeof(int) * (size))) == NULL)
		return (0);
	while (i < size)
	{
		(*range)[i++] = min++;
	}
	return (size);
}
