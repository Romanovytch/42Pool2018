/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:32:30 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 11:30:05 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_abs.h"

int	main()
{
	int	nb;
	int	nb2;
	int	nb3;

	nb = 42;
	nb2 = -100;
	nb3 = 0;
	printf("abs(%d) : %d\n", nb, ABS(nb));
	printf("abs(%d) : %d\n", nb2, ABS(nb2));
	printf("abs(%d) : %d\n", nb3, ABS(nb3));
}
