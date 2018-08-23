/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:08:08 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 19:03:21 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_read.h"

int	emergency(char *buffer)
{
	if (buffer != NULL)
		free(buffer);
	return (FAILURE);
}
