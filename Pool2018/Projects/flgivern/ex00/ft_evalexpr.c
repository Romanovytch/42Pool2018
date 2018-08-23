/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evalexpr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 12:56:00 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 23:29:36 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_priority.h"
#include "ft_list.h"
#include "ft_eval_expr.h"
#include "libft.h"

void	push_token(t_list **pile_tokens, t_list **pile_npi, char operator)
{
	t_list	*last;

	last = ft_list_last(*pile_tokens);
	if (last == NULL)
	{
		push(pile_tokens, operator, 0, TOKEN);
		return ;
	}
	while (check_priority(last->token, operator))
	{
		push(pile_npi, last->token, 0, TOKEN);
		pop(pile_tokens);
		last = ft_list_last(*pile_tokens);
		if (last == NULL)
		{
			push(pile_tokens, operator, 0, TOKEN);
			return ;
		}
	}
	push(pile_tokens, operator, 0, TOKEN);
}

void	depile(t_list **npi, t_list **prev, t_list **prevprev)
{
	t_list	*tmp;
	int		i;
	int		pos;

	tmp = *npi;
	i = 0;
	while (tmp->id != TOKEN)
	{
		*prevprev = *prev;
		*prev = tmp;
		tmp = tmp->next;
	}
	while (g_opp[i].op != tmp->token)
		++i;
	pos = ft_list_getindex(*npi, tmp);
	insert(npi, pos, g_opp[i].f((*prevprev)->nb, (*prev)->nb), NUMBER);
	ft_list_remove_index(npi, pos + 1);
	ft_list_remove_index(npi, pos - 1);
	ft_list_remove_index(npi, pos - 2);
}

int		solve(t_list **npi)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*prevprev;
	int		i;

	i = 0;
	prev = NULL;
	prevprev = NULL;
	if (ft_list_size(*npi) == 1)
		return ((*npi)->nb);
	while (ft_list_size(*npi) != 3)
		depile(npi, &prev, &prevprev);
	tmp = *npi;
	while (g_opp[i].op != tmp->next->next->token)
		++i;
	return (g_opp[i].f((*npi)->nb, (*npi)->next->nb));
}

void	fct(char *expr, t_list **pile_tokens, t_list **pile_npi, int *i)
{
	if (is_nb(expr, *i))
	{
		push(pile_npi, 0, ft_atoi(expr + *i), NUMBER);
		while (is_nb(expr, *i))
			++(*i);
		--(*i);
	}
	else if (is_token(expr[*i]) == OPERATOR)
		push_token(pile_tokens, pile_npi, expr[*i]);
	else if (is_token(expr[*i]) == PARENTHESIS)
		apply_priorities(pile_tokens, pile_npi, expr[*i]);
}

int		eval_expr(char *str)
{
	t_list	*pile_tokens;
	t_list	*pile_npi;
	char	*expr;
	int		i;

	i = 0;
	pile_tokens = NULL;
	pile_npi = NULL;
	expr = ft_compact(str);
	while (expr[i])
	{
		fct(expr, &pile_tokens, &pile_npi, &i);
		if (expr[i] != '\0')
			++i;
	}
	while (ft_list_last(pile_tokens) != NULL)
	{
		push(&pile_npi, ft_list_last(pile_tokens)->token, 0, TOKEN);
		pop(&pile_tokens);
	}
	return (solve(&pile_npi));
}
