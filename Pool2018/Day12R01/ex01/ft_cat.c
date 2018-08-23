/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:04:47 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:37:54 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_cat.h"

void	ft_putnstr(char *str, unsigned int n)
{
	write(1, str, n);
}

int		ft_cat(char *file)
{
	char				buffer[BUFFSIZE];
	int					n_read;
	int					fd;

	fd = 0;
	if (file != NULL)
		if ((fd = open(file, O_RDONLY)) == -1)
			return (FAILURE);
	while ((n_read = read(fd, buffer, BUFFSIZE)) > 0)
		ft_putnstr(buffer, n_read);
	if (fd != 0)
		close(fd);
	return (SUCCESS);
}
