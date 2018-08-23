/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:33:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 13:39:54 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (tab[i] != 0)
		++i;
	--i;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j + 1], tab[j]) < 0)
			{
				c = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = c;
			}
			++j;
		}
		--i;
	}
}
