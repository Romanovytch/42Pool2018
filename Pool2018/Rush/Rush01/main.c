/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:44:40 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/11 16:11:52 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			if (j < 8)
				printf("%d ", tab[i][j] - 48);
			else
				printf("%d\n", tab[i][j] - 48);
			++j;
		}
		++i;
	}
}

int	place(char **tab, int i, int j, int chiffre)
{
	if (tab[i][j] == '.')
		return (1);
	return (0);
}

int	resolve_sudoku(char **tab, int i, int j)
{
	char	chiffre;


	if (i == 9)
		return (0);
	while (j < 9)
	{
		chiffre = '1';
		while (chiffre <= '9')
		{
			if (place(tab, i, j, chiffre) == 1)
			{
				tab[i][j] = chiffre;
				if (j < 8)
					resolve_sudoku(tab, i, j + 1);
				else
					resolve_sudoku(tab, i + 1, 0);		
			}
			++chiffre;
		}
		++j;
	}
	print_tab(tab);
	return (0);
}

int	main(int argc, char **argv)
{
	/*if (error(argc, argv) == 0)
		return (0); */
	resolve_sudoku(argv, 0, 0);
	return (0);
}
