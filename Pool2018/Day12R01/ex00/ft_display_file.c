/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:04:47 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:54:31 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_display_file.h"

void	ft_putnstr_err(char *str, unsigned int n)
{
	write(2, str, n);
}

void	ft_putnstr(char *str, unsigned int n)
{
	write(1, str, n);
}

int		ft_display_file(char *file)
{
	char				buffer[BUFFSIZE];
	unsigned int		n_read;
	int					fd;

	if ((fd = open(file, O_RDONLY)) == FAILURE)
		return (FAILURE);
	while ((n_read = read(fd, buffer, BUFFSIZE)) != 0)
		ft_putnstr(buffer, n_read);
	close(fd);
	return (SUCCESS);
}
