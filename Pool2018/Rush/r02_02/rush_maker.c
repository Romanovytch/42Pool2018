/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colleOXX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:08:42 by groberto          #+#    #+#             */
/*   Updated: 2018/08/19 19:03:12 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	fill_rush(char *c, int xy[2], int ij[2], char *chars)
{
	if (ij[0] == 0 && ij[1] == 0)
		*c = chars[0];
	else if (ij[0] == xy[0] - 1 && ij[1] == xy[1] - 1 && xy[0] > 1 && xy[1] > 1)
		*c = chars[3];
	else if (ij[0] == 0 && ij[1] == xy[1] - 1)
		*c = chars[2];
	else if (ij[0] == xy[0] - 1 && ij[1] == 0)
		*c = chars[1];
	else if (ij[1] == 0 || ij[1] == xy[1] - 1)
		*c = chars[4];
	else if (ij[0] == 0 || ij[0] == xy[0] - 1)
		*c = chars[5];
	else
		*c = ' ';
}

char	*make_rush(int xy[2], char *chars)
{
	int		ij[2];
	char	*output;
	int		k;

	ij[0] = 0;
	ij[1] = 0;
	k = 0;
	if ((output = malloc(sizeof(char) * (xy[0] * xy[1] + 1))) == NULL)
		return (NULL);
	while (ij[1] < xy[1] && xy[1] > 0 && xy[0] > 0)
	{
		ij[0] = 0;
		while (ij[0] < xy[0])
		{
			fill_rush(&output[k], xy, ij, chars);
			ij[0]++;
			k++;
		}
		ij[1]++;
		output[k] = '\n';
		k++;
	}
	output[k] = '\0';
	return (output);
}
