/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:44:07 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 18:23:53 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

long	ft_power(int nb, int power)
{
	int		i;
	long	res;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = nb;
	while (i < power)
	{
		res = res * nb;
		++i;
	}
	return (res);
}

int		check(char *base, int len)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	if (len <= 1)
		return (0);
	while (base[i])
	{
		j = 0;
		nb = 0;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				++nb;
			++j;
		}
		if (nb > 1)
			return (0);
		++i;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	biggestpow;
	long	n;
	int		pw;

	biggestpow = 0;
	n = nbr;
	if (!(check(base, ft_strlen(base))))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n == 0)
		ft_putchar('0');
	while (ft_power(ft_strlen(base), biggestpow) <= n)
		biggestpow++;
	biggestpow--;
	while (biggestpow >= 0)
	{
		pw = n / ft_power(ft_strlen(base), biggestpow);
		ft_putchar(base[pw]);
		n = n - pw * ft_power(ft_strlen(base), biggestpow);
		--biggestpow;
	}
}
