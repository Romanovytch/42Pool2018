/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:52:30 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 23:26:04 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_EXPR_H
# define FT_EVAL_EXPR_H

# define OPERATOR 1
# define PARENTHESIS 2

typedef struct		s_opp
{
	char			op;
	int				(*f)(int a, int b);
}					t_opp;

int					eval_expr(char *str);
int					ft_add(int a, int b);
int					ft_sub(int a, int b);
int					ft_mul(int a, int b);
int					ft_div(int a, int b);
int					ft_mod(int a, int b);

t_opp				g_opp[] =
{
	{'+', &ft_add},
	{'-', &ft_sub},
	{'*', &ft_mul},
	{'/', &ft_div},
	{'%', &ft_mod}
};

#endif
