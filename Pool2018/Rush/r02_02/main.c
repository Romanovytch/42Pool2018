/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:20:15 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 19:03:49 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_read.h"
#include "ft_str.h"
#include "rush.h"

t_rush	g_rush[] =
{

	{RUSH0, "[colle-00]"},
	{RUSH1, "[colle-01]"},
	{RUSH2, "[colle-02]"},
	{RUSH3, "[colle-03]"},
	{RUSH4, "[colle-04]"},
	{NULL, NULL}
};

void	print_rush(char *name, int x, int y, int *first)
{
	if (*first != 0)
		ft_putstr(" || ");
	else
		*first = 1;
	ft_putstr(name);
	ft_putstr(" [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putchar(']');
}

void	get_size(char *input, int *x, int *y)
{
	int	i;

	i = 0;
	while (input[i] != '\n' && input[i])
		++i;
	if (input[i] == '\n')
		*x = i;
	while (input[i])
	{
		if (input[i] == '\n')
			(*y)++;
		++i;
	}
}

int		find_rush(char *input, int size[2])
{
	char	*rush;
	int		i;
	int		first;

	first = 0;
	i = 0;
	while (g_rush[i].chars != NULL)
	{
		if ((rush = make_rush(size, g_rush[i].chars)) == NULL)
			return (FAILURE);
		if (ft_strcmp(rush, input) == 0)
			print_rush(g_rush[i].name, size[0], size[1], &first);
		free(rush);
		++i;
	}
	if (first == 0)
		ft_putstr("aucune");
	return (SUCCESS);
}

int		main(void)
{
	char	*input;
	int		size[2];

	size[0] = 0;
	size[1] = 0;
	input = NULL;
	if ((ft_read(&input)) == FAILURE)
		return (FAILURE);
	get_size(input, &size[0], &size[1]);
	if (find_rush(input, size) == FAILURE)
		return (FAILURE);
	ft_putchar('\n');
	free(input);
	return (SUCCESS);
}
