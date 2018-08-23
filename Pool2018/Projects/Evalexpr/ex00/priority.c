/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:36:03 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 23:37:21 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		is_token(char c)
{
	if (c == '+' || c == '-' || c == '*'
		|| c == '/' || c == '%')
		return (1);
	if (c == '(' || c == ')')
		return (2);
	return (0);
}

int		is_nb(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	if (str[i] == '-' && (i == 0))
		return (1);
	if ((str[i] == '-') && (str[i + 1] >= '0' && str[i + 1] <= '9')
			&& ((str[i - 1] == '('))
		return (1);
	return (0);
}

int		check_priority(char o2, char o1)
{
	if (o2 == '*' || o2 == '/' || o2 == '%')
		return (1);
	if (o2 == '+' || o2 == '-')
		if (o1 == '+' || o1 == '-')
			return (1);
	return (0);
}

void	apply_priorities(t_list **pile_tokens, t_list **pile_npi, char operator)
{
	if (operator == '(')
	{
		push(pile_tokens, operator, 0, TOKEN);
		return ;
	}
	while (ft_list_last(*pile_tokens)->token != '(')
	{
		push(pile_npi, ft_list_last(*pile_tokens)->token, 0, TOKEN);
		pop(pile_tokens);
	}
	pop(pile_tokens);
}
