/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:44:40 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/12 23:38:37 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

int		error(int taille, char **tab);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		chiffre_est_dans_bloc(char **tab, int i, int j, char chiffre)
{
	int	k;
	int	l;

	k = i - (i + 3) % 3;
	while (k < (i - (i + 3) % 3) + 3)
	{
		l = j - (j + 3) % 3;
		while (l < (j - (j + 3) % 3) + 3)
		{
			if (tab[k][l] == chiffre)
				return (1);
			++l;
		}
		++k;
	}
	return (0);
}

int		chiffre_peut_il_etre_placer(char **tab, int i, int j, char chiffre)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (l < 9)
	{
		if (chiffre == tab[i][l])
			return (0);
		++l;
	}
	while (k < 9)
	{
		if (chiffre == tab[k][j])
			return (0);
		++k;
	}
	if (chiffre_est_dans_bloc(tab, i, j, chiffre) == 1)
		return (0);
	return (1);
}

void	print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (j < 8)
			{
				ft_putchar(tab[i][j]);
				ft_putchar(' ');
			}
			else
			{
				ft_putchar(tab[i][j]);
				ft_putchar('\n');
			}
			++j;
		}
		++i;
	}
}

int	fin_sudoku(char **tab, int i, int j, int *nb)
{
	if (i == 9 && j == 0)
	{
		*nb = *nb + 1;
		if (*nb == 1)
			print_tab(tab);
		if (*nb > 1)
			return (STOP);
	}
	return (CONTINUE);
}

int	resolve_sudoku(char **tab, int i, int j, int *nb)
{
	char	chiffre_a_placer;

	if (fin_sudoku(tab, i, j, nb) == STOP)
		return (STOP);
	if (i < 9)
	{
		if (tab[i][j] != '.')
			return (resolve_sudoku(tab, (j == 8) ? i + 1 : i, (j == 8) ? 0 : j + 1, nb));
		chiffre_a_placer = '1';
		while (chiffre_a_placer <= '9')
		{
			if(chiffre_peut_il_etre_placer(tab, i, j, chiffre_a_placer) == 1)
			{
				tab[i][j] = chiffre_a_placer;
				if (resolve_sudoku(tab, (j == 8) ? i + 1 : i, (j == 8) ? 0 : j + 1, nb) == STOP)
					return (STOP);	
				tab[i][j] = '.';
			}
			tab[i][j] = '.';
			++chiffre_a_placer;
		}
	}
	return (CONTINUE);
}

int		main(int argc, char **argv)
{
	int		nb;

	nb = 0;
	if (error(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	resolve_sudoku(&argv[1], 0, 0, &nb);
	return (0);
}

