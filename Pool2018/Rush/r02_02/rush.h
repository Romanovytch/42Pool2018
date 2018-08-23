/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:25:44 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 18:22:07 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define RUSH0 "oooo-|"
# define RUSH1 "/\\\\/**"
# define RUSH2 "AACCBB"
# define RUSH3 "ACACBB"
# define RUSH4 "ACCABB"

typedef struct	s_rush
{
	char	*chars;
	char	*name;
}				t_rush;

char			*make_rush(int size[2], char *chars);

#endif
