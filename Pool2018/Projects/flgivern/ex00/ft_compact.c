/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 03:15:32 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 22:49:17 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			get_space_nbr(char *str)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			compteur++;
		++i;
	}
	return (compteur);
}

char		*ft_compact(char *str)
{
	char	*compacted_str;
	int		i;
	int		j;
	int		len;
	int		space_nbr;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	space_nbr = get_space_nbr(str);
	compacted_str = (char *)malloc(sizeof(char) * (len - space_nbr + 1));
	while (str[i])
	{
		if (!is_space(str[i]))
			compacted_str[j++] = str[i];
		++i;
	}
	compacted_str[j] = '\0';
	return (compacted_str);
}
