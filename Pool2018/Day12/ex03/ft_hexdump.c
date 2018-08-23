/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:23:50 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 00:28:50 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_hexdump.h"

void	ft_print_addr(unsigned int offset)
{
	int		size;
	char	*base;

	base = "0123456789abcdef";
	size = 6;
	if (offset != 0)
		ft_putstr("\n");
	while (size >= 0)
	{
		ft_putchar(base[offset / ft_pow(HEX_SIZE, size)]);
		offset = offset - (offset / ft_pow(HEX_SIZE, size)) * ft_pow(HEX_SIZE, size);
		--size;
	}
}

void	ft_print_hexa_content(char byte)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(' ');
	ft_putchar(base[byte / 16]);
	ft_putchar(base[byte % 16]);
}

void	print_hexdump(char *buffer, unsigned int n_read, unsigned int offset, int current, int nbfiles)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < n_read)
	{

		if (((offset + i) % HEX_SIZE) == 0)
			ft_print_addr(offset + i);
		ft_print_hexa_content(buffer[i]);
		++i;
	}
	while (i < HEX_SIZE && current == nbfiles)
	{
		ft_putstr("   ");
		++i;
	}
}

void	retain_prev_line(unsigned int n_read, unsigned int offset, char *buffer, char **prev_line)
{
	unsigned int	i;
	int				j;

	j = 0;
	i = offset % HEX_SIZE;
	while (i < (offset % HEX_SIZE + n_read))
	{
		(*prev_line)[i] = buffer[j];
		++i;
		++j;
	}
	(*prev_line)[i] = '\0';
}

int	ft_hexdump(char *file, unsigned int *offset, int current, int nbfiles, char **prev_line)
{
	char			*buffer;
	unsigned int	n_read;
	int				fd;
	int				skip;

	fd = 0;
	skip = 0;
	if (file != NULL)
		if ((fd = open(file, O_RDONLY)) == FAILURE)
			return (FAILURE);
	if ((buffer = malloc((HEX_SIZE + 1) * sizeof(char))) == NULL)
		return (FAILURE);
	while ((n_read = read(fd, buffer, HEX_SIZE)) != 0)
	{
		buffer[n_read] = '\0';
		if (n_read == HEX_SIZE && ft_strncmp(*prev_line, buffer, HEX_SIZE) == 0 && skip == 0)
		{
			skip = 1;
			ft_putstr("*\n");
		}
		else if (!(n_read == HEX_SIZE && ft_strncmp(*prev_line, buffer, HEX_SIZE) == 0))
		{
			retain_prev_line(n_read, *offset, buffer, prev_line);
			printf("Retain : %s\n", *prev_line);
			print_hexdump(buffer, n_read, *offset, current, nbfiles);
			skip = 0;
		}
		*offset += n_read;
	}
	if (fd != 0)
		close(fd);
	if (*prev_line != NULL && current == nbfiles)
	{
		ft_print_addr(*offset);
		ft_putstr("\n");
	}
	return (SUCCESS);
}
