/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:20:51 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:34:09 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_hexdump.h"
#include "ft_str.h"

#include <stdio.h>

unsigned int offset;

void	ft_print_addr()
{
	unsigned int	addr;
	int				size;
	char			*base;

	addr = offset;
	base = "0123456789abcdef";
	size = 6;
	while (size >= 0)
	{
		ft_putchar(base[addr / ft_pow(HEX_SIZE, size)]);
		addr = addr - (addr / ft_pow(HEX_SIZE, size)) * ft_pow(HEX_SIZE, size);
		--size;
	}
	offset += HEX_SIZE;
}	

void	print_hexa(char *str)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	ft_print_addr();
	while (str[i])
	{
		ft_putchar(' ');
		ft_putchar(base[str[i] / 16]);
		ft_putchar(base[str[i] % 16]);
		++i;
	}
	ft_putchar('\n');
}

int	ft_hexdump(char **buffer, char **prev_line, int fd, int wasread)
{
	int		n_read;
	int		match;

	match = 0;
	if (wasread != HEX_SIZE && wasread != 0)
	{
		n_read = read(fd, *buffer + wasread, HEX_SIZE - wasread);
		(*buffer)[n_read + wasread] = '\0';
		if (n_read == HEX_SIZE - wasread)
		{
			ft_strlcpy(*prev_line, *buffer, HEX_SIZE + 1);
			print_hexa(*buffer);
		}
	}
	while ((n_read = read(fd, *buffer, HEX_SIZE)) != 0)
	{
		//printf("Buffer content : %s | Prev_line content : %s\n", *buffer, *prev_line);
		if ((ft_strcmp(*buffer, *prev_line) == 0) && (match == 0))
		{
			ft_putstr("*\n");
			match = 1;
		}
		else if (n_read == HEX_SIZE)
		{
			match = 0;
			(*buffer)[n_read] = '\0';
			print_hexa(*buffer);
			ft_strlcpy(*prev_line, *buffer, HEX_SIZE + 1);
		}
		else
		{
			(*buffer)[n_read] = '\0';
			return (n_read);
		}
	}
	return (n_read);
}
