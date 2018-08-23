/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:21:06 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/17 11:50:09 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define HEX_SIZE 16
# define FAILURE -1
# define SUCCESS 0

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strndup(char *str, unsigned int size);
int		ft_strncmp(char *dest, char *src, unsigned int n);
int		ft_hexdump(char *file, unsigned int *offset, int current, int nbfiles, char **prev_line);
int		ft_pow(int nb, int power);

#endif
