/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:24:18 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/06 23:50:05 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	if (c == '\0')
		return (2);
	else
		return (0);
}

int		count_words(char *str, char *charset)
{
	int	nbwords;
	int	i;

	i = 0;
	nbwords = 0;
	while (str[i])
	{
		if (i == 0 && !(is_separator(str[i], charset)))
		{
			nbwords++;
			while (!(is_separator(str[i], charset)))
				++i;
		}
		while (is_separator(str[i], charset) == 1)
			++i;
		if (str[i] == '\0')
			return (nbwords);
		nbwords++;
		while (!(is_separator(str[i], charset)))
			++i;
	}
	return (nbwords);
}

int		get_len(char *str, int *i, char *charset)
{
	int	j;

	j = 0;
	while (is_separator(str[*i], charset) == 1)
		++(*i);
	if (str[*i] == '\0')
		return (-1);
	while (!(is_separator(str[(*i)++], charset)))
		++j;
	return (j);
}

char	*add_word(char **str, char *charset)
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
		if ((j = get_len(*str, &i, charset)) == -1)
			return (0);
		word = malloc((j + 1) * sizeof(char));
		i = i - j - 1;
		j = 0;
		while (!(is_separator((*str)[i], charset)))
			word[j++] = (*str)[i++];
		word[j] = '\0';
		*str += i;
		return (word);
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nbwords;
	int		i;

	i = 0;
	nbwords = count_words(str, charset);
	tab = malloc((nbwords + 1) * sizeof(char *));
	while (i < nbwords + 1)
		tab[i++] = add_word(&str, charset);
	return (tab);
}
