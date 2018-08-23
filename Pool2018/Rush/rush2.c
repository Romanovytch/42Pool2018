/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colleOXX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:08:42 by groberto          #+#    #+#             */
/*   Updated: 2018/08/19 16:51:16 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x, int y, char *chars)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (j < y && y > 0 && x > 0)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 && j == 0)
				ft_putchar(chars[0]);
			else if	(i == x - 1 && j == y - 1 && x > 1 && y > 1)
				ft_putchar(chars[3]);
			else if (i == 0 && j == y - 1)
				ft_putchar(chars[2]);
			else if (i == x - 1 && j == 0)
				ft_putchar(chars[1]);
			else if (j == 0 || j == y - 1)
				ft_putchar(chars[4]);
			else if (i == 0 || i == x - 1)
				ft_putchar(chars[5]);
			else
				ft_putchar(' ');
			i++;
			k++;
		}
		j++;
		ft_putchar('\n');
		k++;
	}
}

int main (int argc, char **argv)
{
	rush(atoi(argv[1]),atoi(argv[2]), "AACCBB");
	return (0);
}
