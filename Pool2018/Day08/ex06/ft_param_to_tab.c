/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:45:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/07 13:44:18 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\0')
		return (2);
	else
		return (0);
}

int		count_words(char *str)
{
	int	nbwords;
	int	i;

	i = 0;
	nbwords = 0;
	while (str[i])
	{
		if (i == 0 && !(is_separator(str[i])))
		{
			nbwords++;
			while (!(is_separator(str[i])))
				++i;
		}
		while (is_separator(str[i]) == 1)
			++i;
		if (str[i] == '\0')
			return (nbwords);
		nbwords++;
		while (!(is_separator(str[i])))
			++i;
	}
	return (nbwords);
}

int		get_len(char *str, int *i)
{
	int	j;

	j = 0;
	while (is_separator(str[*i]) == 1)
		++(*i);
	if (str[*i] == '\0')
		return (-1);
	while (!(is_separator(str[(*i)++])))
		++j;
	return (j);
}

char	*add_word(char **str)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	word = NULL;
	if ((*str)[i] == '\0')
		return (0);
	while ((*str)[i])
	{
		if ((j = get_len(*str, &i)) == -1)
			return (0);
		word = malloc((j + 1) * sizeof(char));
		i = i - j - 1;
		j = 0;
		while (!(is_separator((*str)[i])))
			word[j++] = (*str)[i++];
		word[j] = '\0';
		*str += i;
		return (word);
	}
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		nbwords;
	int		i;

	i = 0;
	nbwords = count_words(str);
	tab = malloc((nbwords + 1) * sizeof(char *));
	while (i < nbwords + 1)
		tab[i++] = add_word(&str);
	return (tab);
}

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
