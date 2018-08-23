/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:59:31 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/22 15:10:07 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	errno = 0;
	if (argc == 1)
		ft_cat(NULL);
	else
	{
		while (i < argc)
		{
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
