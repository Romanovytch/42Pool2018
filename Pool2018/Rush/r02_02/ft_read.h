/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:27:49 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 18:53:06 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# define SUCCESS 0
# define FAILURE -1
# define BSIZE 4096

int	ft_read(char **input);
int	emergency(char *buffer);

#endif
