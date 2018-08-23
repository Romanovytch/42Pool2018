/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:22:30 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 19:03:36 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_read.h"
#include "ft_str.h"

int		ft_realloc(char **buffer, char **input, unsigned int *i)
{
	char	*tmp;

	if ((tmp = (char *)malloc((BSIZE * *i) * sizeof(char))) == NULL)
		return (emergency(*input));
	tmp = ft_strncpy(tmp, *input, (BSIZE * *i));
	free(*input);
	if ((*buffer = (char *)malloc((BSIZE * (*i + 1)) * sizeof(char))) == NULL)
		return (emergency(tmp));
	*input = *buffer;
	*buffer = ft_strncpy(*buffer, tmp, (BSIZE * *i));
	*buffer += (BSIZE * *i);
	free(tmp);
	++(*i);
	return (SUCCESS);
}

int		ft_read(char **input)
{
	unsigned int		size;
	unsigned int		i;
	int					n_read;
	char				*buffer;

	buffer = NULL;
	size = 0;
	i = 1;
	if ((buffer = (char *)malloc(BSIZE * sizeof(char))) == NULL)
		return (emergency(buffer));
	*input = buffer;
	while ((n_read = read(0, buffer, BSIZE)) != 0)
	{
		if (n_read == -1)
			return (emergency(*input));
		buffer += n_read;
		size += n_read;
		if (size == (BSIZE * i))
			if (ft_realloc(&buffer, input, &i) == FAILURE)
				return (FAILURE);
	}
	(*input)[size] = '\0';
	return (SUCCESS);
}
