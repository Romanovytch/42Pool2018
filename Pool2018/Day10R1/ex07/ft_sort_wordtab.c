/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:57:13 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 10:31:32 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		++i;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

void	ft_sort_wordtab(char **tab)
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
			if (ft_strcmp(tab[j + 1], tab[j]) < 0)
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
