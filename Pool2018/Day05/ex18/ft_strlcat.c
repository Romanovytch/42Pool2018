/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:54:46 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 10:40:14 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	int				j;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	while (dest[i])
		++i;
	while (i < (size - 1) && src[j] != '\0')
		dest[i++] = src[j++];
	while (i < size)
		dest[i++] = '\0';
	if (size > dest_len)
		return (dest_len + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
