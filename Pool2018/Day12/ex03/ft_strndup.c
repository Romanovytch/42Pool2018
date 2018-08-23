/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:20:52 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/16 23:13:13 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, unsigned int size)
{
	char	*str;
	unsigned int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (src[i] && i < size)
	{
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
