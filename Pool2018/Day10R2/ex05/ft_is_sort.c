/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:27:43 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/14 14:04:02 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while ((i < (length - 1)) && diff == 0)
	{
		diff = f(tab[i], tab[i + 1]);
		++i;
	}
	while (i < (length - 1))
	{
		if (diff < 0)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
		}
		else
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		}
		++i;
	}
	return (1);
}
