/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:03:18 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/23 01:55:09 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# define SUCCESS 0
# define FAILURE -1
# define BUFFSIZE 1024
# define MISSING_FILENAME "File name missing.\n"
# define TOOMANY_FILES "Too many arguments.\n"

int		ft_display_file(char *file);
void	ft_putnstr(char *str, unsigned int n);
void	ft_putnstr_err(char *str, unsigned int n);
int		check(int ac);
int		ft_strlen(char *str);

#endif
