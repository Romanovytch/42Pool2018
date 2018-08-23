/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:27:43 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 10:46:05 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	diff;

	i = 0;
	if (i < (length - 1))
		diff = f(tab[i], tab[i + 1]);
	while (i < (length - 1))
	{
		if ((f(tab[i], tab[i + 1]) != diff) && (f(tab[i], tab[i + 1]) != 0))
			return (0);
		++i;
	}
	return (1);
}
