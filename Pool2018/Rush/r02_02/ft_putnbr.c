/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:19:24 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 18:04:14 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void				ft_putnbr(int nb)
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
