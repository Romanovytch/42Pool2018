/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:45:26 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 10:34:44 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_do_op.h"
#include "ft_opp.h"

int		ft_usage(int a, int b)
{
	int	i;

	i = 0;
	(void)a;
	(void)b;
	ft_putstr("error : only [ ");
	while (ft_strcmp(g_opptab[i].op, "") != 0)
	{
		ft_putstr(g_opptab[i].op);
		ft_putchar(' ');
		++i;
	}
	ft_putstr("] are accepted.\n");
	return (FAILURE);
}

int		do_op(int a, char *op, int b)
{
	int	i;

	i = 0;
	if (check(a, op, b) == FAILURE)
		return (FAILURE);
	while (ft_strcmp(g_opptab[i].op, "") != 0)
	{
		if (ft_strcmp(g_opptab[i].op, op) == 0)
		{
			ft_putnbr(g_opptab[i].f(a, b));
			ft_putchar('\n');
			return (SUCCESS);
		}
		++i;
	}
	g_opptab[i].f(a, b);
	return (FAILURE);
}
