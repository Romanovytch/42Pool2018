/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:18:58 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/06 19:09:17 by flgivern         ###   ########.fr       */
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

char	*create_nbr(long *dec, long *bpow, int *is_sign, char *base_to)
{
	char	*nbr;

	if (*dec < 0)
	{
		++(*is_sign);
		*dec = *dec * -1;
	}
	while (ft_power(ft_strlen(base_to), *bpow) <= *dec)
		(*bpow)++;
	(*bpow)--;
	nbr = (char *)malloc(sizeof(char) * (*bpow + 2 + *is_sign));
	return (nbr);
}

char	*nbr_to_base(long dec, char *base_to)
{
	long	bpow;
	int		is_sign;
	char	*nbr;
	int		i;

	i = 0;
	bpow = 0;
	is_sign = 0;
	nbr = create_nbr(&dec, &bpow, &is_sign, base_to);
	if (dec == 0)
		nbr[i++] = '0';
	if (is_sign > 0)
		nbr[i++] = '-';
	while (bpow >= 0)
	{
		nbr[i] = base_to[dec / ft_power(ft_strlen(base_to), bpow)];
		dec = dec - (dec / ft_power(ft_strlen(base_to), bpow)) *
			ft_power(ft_strlen(base_to), bpow);
		--bpow;
		++i;
	}
	nbr[i] = '\0';
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	dec;
	int		i;
	int		j;
	int		sign;

	dec = 0;
	sign = 1;
	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
	{
		nbr = nbr + 1;
		if ((nbr - 1)[0] == '-')
			sign = -1;
	}
	while (i < ft_strlen(nbr))
	{
		j = 0;
		while (nbr[i] != base_from[j])
			++j;
		dec += j * ft_power(ft_strlen(base_from), ft_strlen(nbr) - i - 1);
		++i;
	}
	return (nbr_to_base(dec * sign, base_to));
}
