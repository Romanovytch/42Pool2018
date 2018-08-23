/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:14:04 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/04 14:33:27 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_spacenb(int size)
{
	int spacenb;
	int spacestoadd;
	int i;

	i = 0;
	spacenb = 2 * size;
	spacestoadd = 2;
	while (i < size)
	{
		spacenb += i;
		if (i % 2 == 0)
			spacestoadd++;
		++i;
		if (i < size)
			spacenb += spacestoadd;
	}
	return (spacenb);
}

void	print_stage(int chars[2], int size, int etage, int j)
{
	int i;
	int door;

	i = 0;
	door = etage / 2 + 1;
	while (i < chars[1])
	{
		ft_putchar(' ');
		++i;
	}
	i = 0;
	ft_putchar('/');
	while (i < chars[0])
	{
		if (size >= 5 && j == ((size + 2) + ((size + 2) - size - size % 2)) / 2
			&& (i == (chars[0] / 2 + door) - 2) && (etage == (size - 1)))
			ft_putchar('$');
		else if ((j > ((size + 2) - size - size % 2)) && (etage == (size - 1))
				&& (i > (chars[0] / 2 - door) && (i < (chars[0] / 2 + door))))
			ft_putchar('|');
		else
			ft_putchar('*');
		++i;
	}
	ft_putchar('\\');
}

int		print_sastantua(int i, int size, int *spacenb, int starsnb)
{
	int	j;
	int	chars[2];

	j = 0;
	chars[0] = starsnb;
	chars[1] = *spacenb;
	while (j < 3 + i)
	{
		print_stage(chars, size, i, j);
		ft_putchar('\n');
		++j;
		chars[0] += 2;
		--(*spacenb);
		chars[1] = *spacenb;
	}
	return (chars[0]);
}

void	sastantua(int size)
{
	int	starsnb;
	int	spacenb;
	int starstoadd;
	int i;

	i = 0;
	starsnb = 1;
	spacenb = get_spacenb(size);
	starstoadd = 1;
	while (i < size)
	{
		if (i % 2 == 0)
			++starstoadd;
		starsnb = print_sastantua(i, size, &spacenb, starsnb);
		starsnb += starstoadd * 2;
		spacenb -= starstoadd;
		++i;
	}
}
