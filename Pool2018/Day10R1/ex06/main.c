/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:32:39 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 14:43:27 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (FAILURE);
	if (do_op(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3])) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
