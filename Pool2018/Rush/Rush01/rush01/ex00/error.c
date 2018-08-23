/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphanor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:12:23 by aphanor           #+#    #+#             */
/*   Updated: 2018/08/12 23:39:17 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		nb_appears_multiple_times(char *line)
{
	int	i;
	int	j;
	int	compteur;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		compteur = 0;
		while (line[j] != '\0')
		{
			if ((line[i] >= '0' && line[i] <= '9') && line[j] == line[i])
				compteur++;
			++j;
		}
		if (compteur > 1)
			return (1);
		++i;
	}
	return (0);
}

int		error(int taille, char **tab)
{
	int i;
	int j;

	i = 1;
	if (taille != 10)
		return (0);
	while (i < 10)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (!((tab[i][j] >= '0' && tab[i][j] <= '9') || tab[i][j] == '.'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		if (nb_appears_multiple_times(tab[i]))
			return (0);
		i++;
	}
	return (1);
}


