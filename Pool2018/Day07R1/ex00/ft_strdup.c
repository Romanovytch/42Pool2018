/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:20:52 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 22:43:30 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
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
