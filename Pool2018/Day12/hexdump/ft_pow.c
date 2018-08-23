/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:51:05 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/16 21:15:06 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nb, int power)
{
	int	i;
	int	res;

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
