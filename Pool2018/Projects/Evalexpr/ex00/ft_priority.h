/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priority.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:37:00 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 22:39:29 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIORITY_H
# define FT_PRIORITY_H

# include "ft_list.h"

int		is_token(char c);
int		is_nb(char *str, int i);
int		check_priority(char o2, char o1);
void	apply_priorities(t_list **pile_tokens,
		t_list **pile_npi, char op);

#endif
