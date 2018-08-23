/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:47:56 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 09:51:33 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*pos;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			pos = &str[i];
			while (str[i] == to_find[j] && to_find[j] != '\0')
			{
				++i;
				++j;
			}
			i = i - j;
			if (to_find[j] == '\0')
				return (pos);
		}
		++i;
	}
	return (0);
}
