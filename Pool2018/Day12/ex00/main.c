/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:59:31 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/16 00:13:08 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	if (check(argc) == FAILURE)
		return (FAILURE);
	ft_display_file(argv[1]);
	return (SUCCESS);
}
