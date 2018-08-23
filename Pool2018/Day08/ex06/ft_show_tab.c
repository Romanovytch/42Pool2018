/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:02:42 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/07 02:46:03 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	ft_putnbr(int nb)
{
	long			pw;
	char			digit;
	long			n;

	n = nb;
	pw = 1;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (pw <= n)
	{
		while (pw <= n)
			pw *= 10;
		pw /= 10;
	}
	while (pw > 0)
	{
		digit = n / pw;
		ft_putchar(digit + '0');
		n = n % pw;
		pw /= 10;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != 0)
		{
			ft_putstr(par[i].tab[j]);
			ft_putchar('\n');
			++j;
		}
		++i;
	}
}
