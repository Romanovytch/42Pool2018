/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:39:33 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/01 12:29:30 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	double	div;
	double	mod;

	div = (*a) / (*b);
	mod = (*a) % (*b);
	*a = div;
	*b = mod;
}
