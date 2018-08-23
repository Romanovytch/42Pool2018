/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:01:27 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/15 19:03:08 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

# define FAILURE -1
# define SUCCESS 0

typedef struct	s_opp
{
	char		*op;
	int			(*f)(int, int);
}				t_opp;

void			ft_putchar(char c);
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
int				do_op(int a, char *op, int b);
int				check(int a, char *op, int b);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_do_op(int a, char *op, int b);
int				ft_check(int a, char *op, int b);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);

#endif
