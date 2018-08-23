/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:41:16 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/22 12:15:54 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define SUCCESS 0
# define FAILURE -1
# define HEX_SIZE 16

int		ft_hexdump(char **buffer, char **prev_line, int fd, int wasread);

#endif
