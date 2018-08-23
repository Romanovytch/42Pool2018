/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:45:26 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 14:43:06 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "do_op.h"

t_op	g_optab[6] =
{
	{"+", &add},
	{"-", &sub},
	{"*", &mul},
	{"/", &divi},
	{"%", &mod},
	{NULL, NULL}
};

int		do_op(int a, char *op, int b)
{
	int	i;

	i = 0;
	if (check(a, op, b) == FAILURE)
		return (FAILURE);
	while (g_optab[i].op != NULL)
	{
		if (ft_strcmp(g_optab[i].op, op) == 0)
		{
			ft_putnbr(g_optab[i].f(a, b));
			ft_putchar('\n');
			return (SUCCESS);
		}
		++i;
	}
	ft_putnbr(0);
	ft_putchar('\n');
	return (FAILURE);
}
