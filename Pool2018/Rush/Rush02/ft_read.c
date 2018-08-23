/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:22:30 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/18 18:03:50 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_read.h"
#include "ft_str.h"

int		ft_realloc(char **buffer, char **total, unsigned int *i)
{
	char	*tmp;

	if ((tmp = (char *)malloc((BUFFSIZE * *i) * sizeof(char))) == NULL)
		return (FAILURE);
	tmp = ft_strncpy(tmp, *total, (BUFFSIZE * *i));
	free(*total);
	if ((*buffer = (char *)malloc((BUFFSIZE * (*i + 1)) * sizeof(char))) == NULL)
		return (FAILURE);
	*total = *buffer;
	*buffer = ft_strncpy(*buffer, tmp, (BUFFSIZE * *i));
	*buffer += (BUFFSIZE * *i);
	free(tmp);
	++(*i);
	return (SUCCESS);
}

int	ft_read(char **input)
{
	unsigned int		size;
	unsigned int		i;
	int					n_read;
	char				*buffer;

	buffer = NULL;
	size = 0;
	i = 1;
	if ((buffer = (char *)malloc(BUFFSIZE * sizeof(char))) == NULL)
		return (emergency(buffer));
	*input = buffer;
	while ((n_read = read(0, buffer, 1)) != 0)
	{
		buffer++;
		if (n_read == -1)
			return (emergency(*input));
		size++;
		if (size == (BUFFSIZE * i))
			if (ft_realloc(&buffer, input, &i) == FAILURE)
				return (FAILURE);
	}
	(*input)[size] = '\0';
	return (SUCCESS);
}
