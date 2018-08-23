/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:08:22 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/22 15:09:13 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	int				i;
	unsigned int	offset;
	char			*prev_line;

	i = 1;
	offset = 0;
	prev_line = (char *)malloc(sizeof(char) * (HEX_SIZE + 1));
	if (argc == 1)
		return (ft_hexdump(NULL, &offset, i, 1, &prev_line));
	while (i < argc)
	{
		ft_hexdump(argv[i], &offset, i, argc - 1, &prev_line);
		++i;
	}
	printf("Retain main : %s\n", prev_line);
	return (SUCCESS);
}
