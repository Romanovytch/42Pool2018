/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:52:52 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/05 19:15:41 by flgivern         ###   ########.fr       */
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

int		check_base(char *base)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	if (base == 0 || ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = 0;
		c = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				c++;
			++j;
		}
		if (c > 1)
			return (0);
		++i;
	}
	return (1);
}

int		check_str(char *str, char *base)
{
	int	i;
	int	content;
	int	j;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
	{
		j = 0;
		content = 0;
		while (base[j])
		{
			if (str[i] == base[j] || ((str[i] == '+' || str[i] == '-')
				&& (str[i + 1] >= '0' && str[i + 1] <= '9')))
				content = 1;
			++j;
		}
		if (content == 0)
			return (0);
		++i;
	}
	return (1);
}

long	ft_pow(int nb, int power)
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

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	if ((check_str(str, base) == 0) || (check_base(base) == 0))
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		str = str + 1;
		if ((str - 1)[0] == '-')
			sign = -1;
	}
	while (i < ft_strlen(str))
	{
		j = 0;
		while (base[j] != str[i])
			++j;
		nbr += j * ft_pow(ft_strlen(base), ft_strlen(str) - i - 1);
		++i;
	}
	return (nbr * sign);
}
