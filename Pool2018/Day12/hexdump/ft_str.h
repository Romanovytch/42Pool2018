/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:40:15 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 00:24:10 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strlcpy(char *dest, char *src, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
long	ft_pow(int value, int power);

#endif
