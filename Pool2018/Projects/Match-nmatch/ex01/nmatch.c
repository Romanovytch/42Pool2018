/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 16:09:13 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/12 20:16:25 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	nmatch(char *s1, char *s2)
{
	int	nbmatch;

	if (*s2 == '*')
	{
		if (*s1)
		{
			nbmatch = nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1);
			return (nbmatch);
		}
		else
			return (nmatch(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1 && *s2)
			return (nmatch(s1 + 1, s2 + 1));
		else if (!(*s1 && *s2))
			return (1);
	}
	return (0);
}
