/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:18:07 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 12:51:34 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	check(int a, char *op, int b)
{
	(void)a;
	if (b == 0 && (op[0] == '/' || op[0] == '%'))
	{
		if (op[0] == '/')
			ft_putstr("Stop : division by zero\n");
		if (op[0] == '%')
			ft_putstr("Stop : modulo by zero\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
