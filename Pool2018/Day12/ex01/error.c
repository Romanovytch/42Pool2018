/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:31:04 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 02:04:15 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "ft_cat.h"

void	ft_puterrstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	write(2, str, i);
}

int		check_error(int errcode, char *file)
{
	if (errcode != 0)
	{
		ft_puterrstr("cat: ");
		ft_puterrstr(file);
		ft_puterrstr(": ");
	}
	if (errcode == EACCES)
		ft_puterrstr("Permission denied\n");
	else if (errcode == ENOENT)
		ft_puterrstr("No such file or directory\n");
	else if (errcode == EISDIR)
		ft_puterrstr("Is a directory\n");
	if (errcode != 0)
		return (FAILURE);
	return (SUCCESS);
}
