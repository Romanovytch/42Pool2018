/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:54:45 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 02:56:48 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_tail(char *input, char *nb, int size)
{
	int	i;

	i = 0;
	if (nb[0] == '+')
	{
		while (i < size - 1)
			++i;
		if (ft_strlen(input) > i)
			ft_putstr(input + i);
		return ;
	}
	while (input[i])
		++i;
	if (size > i)
		size = i;
	while (size)
		ft_putchar(input[i - (size--)]);
}
