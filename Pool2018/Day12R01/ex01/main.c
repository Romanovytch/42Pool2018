/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:59:31 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 15:43:59 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_cat(NULL);
	else
	{
		while (i < argc)
		{
			errno = 0;
			if (ft_strcmp(argv[i], "-") == 0)
				ft_cat(NULL);
			else
				ft_cat(argv[i]);
			check_error(errno, argv[i]);
			++i;
		}
	}
	return (SUCCESS);
}
