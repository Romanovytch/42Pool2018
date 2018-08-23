/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:54:46 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 10:39:43 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;
	int	append;

	i = 0;
	j = 0;
	while (dest[i])
		++i;
	append = ft_strlen(src);
	while (j < nb && src[j] != '\0')
		dest[i++] = src[j++];
	while (j < nb)
	{
		dest[i++] = '\0';
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
