/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:45:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/07 02:45:02 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				**ft_split_whitespaces(char *str);

int					ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		size;
	char	*str;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	size = ft_strlen(src);
	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*tab;
	int				i;

	i = 0;
	tab = malloc(sizeof(t_stock_par) * (ac + 1));
	while (i < ac)
	{
		tab[i].size_param = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].tab = ft_split_whitespaces(av[i]);
		++i;
	}
	tab[i].str = 0;
	return (tab);
}
