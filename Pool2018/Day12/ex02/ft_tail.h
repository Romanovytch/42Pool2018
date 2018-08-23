/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:10:39 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 03:13:06 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# define FAILURE -1
# define SUCCESS 0
# define BSIZE 4096

int		emergency(char *buffer);
int		ft_atoi(char *str);
int		ft_tail(char *input, char *nb, int n);
int		ft_read(char **input, int fd);
int		check_error(int errcode, char *file);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

#endif
