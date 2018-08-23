/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 15:57:50 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 19:14:43 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	char	*base;
	int		nb;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		nb = str[i];
		if ((str[i] < 32 && str[i] >= 0) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			else
			{
				ft_putchar(base[nb / 16]);
				nb = nb - 16;
			}
			ft_putchar(base[nb % 16]);
		}
		else
			ft_putchar(str[i]);
		++i;
	}
}
