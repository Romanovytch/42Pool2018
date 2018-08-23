/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 01:50:35 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/06 16:40:52 by flgivern         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	append;

	i = 0;
	j = 0;
	while (dest[i])
		++i;
	append = ft_strlen(src);
	while (j < append)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	if ((str = (char *)malloc(sizeof(char) * (len + argc))) == NULL)
		return (NULL);
	str[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i++]);
		if (i != argc)
			ft_strcat(str, "\n");
	}
	return (str);
}
