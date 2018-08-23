/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 01:31:05 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/01 10:10:57 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_comb(char comb[])
{
	while (comb[3] <= '9')
	{
		ft_putchar(comb[0]);
		ft_putchar(comb[1]);
		ft_putchar(' ');
		ft_putchar(comb[2]);
		ft_putchar(comb[3]);
		if (comb[0] != '9' || comb[1] != '8' ||
			comb[2] != '9' || comb[3] != '9')
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		comb[3] = comb[3] + 1;
	}
}

void	ft_print_comb2(void)
{
	char	comb[4];

	comb[0] = '0';
	comb[1] = '0';
	comb[2] = '0';
	comb[3] = '1';
	while (comb[0] <= '9')
	{
		while (comb[1] <= '9')
		{
			comb[2] = comb[0];
			while (comb[2] <= '9')
			{
				print_comb(comb);
				comb[3] = '0';
				comb[2] = comb[2] + 1;
			}
			comb[1] = comb[1] + 1;
			comb[3] = comb[1] + 1;
		}
		comb[1] = '0';
		comb[0] = comb[0] + 1;
		comb[3] = comb[1] + 1;
	}
}
