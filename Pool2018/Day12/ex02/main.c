/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:20:15 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 03:23:41 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "ft_tail.h"
#include "ft_str.h"

void	print_filename(char *file)
{
	ft_putstr("==> ");
	ft_putstr(file);
	ft_putstr(" <==\n");
}

int		do_tail(char **input, char *file, int fd, int argc)
{
	if (ft_read(input, fd) == FAILURE)
		return (FAILURE);
	if (argc > 4)
		print_filename(file);
	return (SUCCESS);
}

int		main(int argc, char **argv)
{
	char	*input;
	int		i;
	int		fd;

	i = 3;
	if (argc < 4)
		return (FAILURE);
	while (i < argc)
	{
		errno = 0;
		input = NULL;
		fd = open(argv[i], O_RDONLY);
		if (fd != -1 && i >= 4)
			ft_putchar('\n');
		if (check_error(errno, argv[i]) == SUCCESS)
		{
			do_tail(&input, argv[i], fd, argc);
			ft_tail(input, argv[2], ft_atoi(argv[2]));
			if (input != NULL)
				free(input);
		}
		++i;
	}
	return (SUCCESS);
}
