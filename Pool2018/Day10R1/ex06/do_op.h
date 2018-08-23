/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:01:27 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/08 12:49:52 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# define FAILURE -1
# define SUCCESS 0

typedef struct	s_op
{
	char		*op;
	int			(*f)(int, int);
}				t_op;

void			ft_putchar(char c);
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				do_op(int a, char *op, int b);
int				check(int a, char *op, int b);
int				add(int a, int b);
int				sub(int a, int b);
int				mul(int a, int b);
int				divi(int a, int b);
int				mod(int a, int b);

#endif
