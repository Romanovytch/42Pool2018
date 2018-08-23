/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:20:15 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/18 18:18:16 by flgivern         ###   ########.fr       */
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
	ft_putchar('[');
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
	(*y)++;
	while (input[i])
	{
		if (input[i] == '\n')
			(*y)++;
		++i;
	}
}

int	main()
{
	char	*input;
	char	*rush;
	int		x;
	int		y;
	int		first;
	int		i;

	first = 0;
	x = 0;
	y = 0;
	i = 0;
	input = NULL;
	if ((ft_read(&input)) == FAILURE)
		return (FAILURE);
	get_size(input, &x, &y);
	while (g_rush[i].chars != NULL)
	{
		rush = make_rush(x, y, g_rush[i].chars);
		if (ft_strcmp(rush, input) == 0)
			print_rush(gtab[i].name, x, y, &first);
		++i;
	}
	if (first == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
	free(input);
	return (SUCCESS);
}
