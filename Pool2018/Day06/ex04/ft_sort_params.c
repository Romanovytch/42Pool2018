/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 13:52:37 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/02 15:30:25 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

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

char	**sort_table(char **tab, int size)
{
	int		i;
	int		j;
	char	*c;

	i = size - 1;
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
	return (tab);
}

void	print_table(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		++i;
	}
}

int		main(int argc, char **argv)
{
	char	**tab;

	tab = sort_table(argv + 1, argc - 1);
	print_table(tab, argc - 1);
	return (0);
}
