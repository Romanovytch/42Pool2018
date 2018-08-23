/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 19:08:22 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:29:03 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_str.h"
#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	char	*buffer;
	char	*prev_line;
	int		wasread;
	int		fd;
	int		i;

	i = 1;
	wasread = 0;
	buffer = (char *)malloc(sizeof(char) * (HEX_SIZE + 1));
	prev_line = (char *)malloc(sizeof(char) * (HEX_SIZE + 1));
	if (argc < 2)
		return (FAILURE);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		wasread = ft_hexdump(&buffer, &prev_line, fd, wasread);
		close(fd);
		++i;
	}
	ft_putstr("\nSUITE MAIN : ");
	ft_putstr(buffer);
	return (SUCCESS);
}
