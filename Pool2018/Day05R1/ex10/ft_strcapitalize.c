/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:17:36 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/04 19:27:18 by flgivern         ###   ########.fr       */
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

int		is_separator(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')))
		return (1);
	return (0);
}

char	*to_lower(char *str, int *i)
{
	if (str[*i] >= 'a' && str[*i] <= 'z')
	{
		str[*i] -= ('a' - 'A');
		++(*i);
	}
	else if (str[*i] >= 'A' && str[*i] <= 'Z')
		++(*i);
	while (!(is_separator(str[*i])))
	{
		if (str[*i] >= 'A' && str[*i] <= 'Z')
			str[*i] += ('a' - 'A');
		++(*i);
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && str[i] != '\0')
	{
		if (i == 0)
			str = to_lower(str, &i);
		else
		{
			if (is_separator(str[i - 1]))
				str = to_lower(str, &i);
		}
		++i;
	}
	return (str);
}
