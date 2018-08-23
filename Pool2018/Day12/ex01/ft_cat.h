/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:03:18 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/17 13:11:19 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# define SUCCESS 0
# define FAILURE 1
# define BUFFSIZE 29696

int		ft_cat(char *file);
void	ft_putnstr(char *str, unsigned int n);
int		check(int ac);
int		ft_strlen(char *str);
int		check_error(int errcode, char *file);
int		ft_strcmp(char *s1, char *s2);

#endif
