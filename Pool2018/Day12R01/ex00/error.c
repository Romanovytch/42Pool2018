/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:17:55 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:55:59 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int	check(int ac)
{
	if (ac < 2)
	{
		ft_putnstr_err(MISSING_FILENAME, ft_strlen(MISSING_FILENAME));
		return (FAILURE);
	}
	if (ac > 2)
	{
		ft_putnstr_err(TOOMANY_FILES, ft_strlen(TOOMANY_FILES));
		return (FAILURE);
	}
	return (SUCCESS);
}
