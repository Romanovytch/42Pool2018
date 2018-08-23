/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:44:10 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/17 16:37:42 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

long	ft_pow(long nb, long power)
{
	int		i;
	long	res;

	i = 1;
	if (power == 0)
		return (1);
	res = nb;
	while (i < power)
	{
		res = res * nb;
		++i;
	}
	return (res);
}

void	ft_puthexa(long nb, char base[], int nbchar)
{
	--nbchar;
	while (nbchar >= 0)
	{
		ft_putchar(base[nb / ft_pow(16, nbchar)]);
		nb = nb - (nb / ft_pow(16, nbchar)) * ft_pow(16, nbchar);
		--nbchar;
	}
}

void	print_content(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = i;
	while (i < size && i < (j + 16))
	{
		if (*(((char *)addr) + i) < 32 || *(((char *)addr) + i) == 127)
			ft_putchar('.');
		else
			ft_putchar(*(((char *)addr) + i));
		++i;
	}
}

void	print_hexa_content(void *addr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = i;
	while (i < size && i < (j + 16))
	{
		ft_puthexa((*((char *)addr + i)), "0123456789abcdef", 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		++i;
	}
	while (i < (j + 16))
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2 == 1)
			ft_putchar(' ');
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_puthexa(i, "0123456789abcdef", 8);
		ft_putchar(':');
		ft_putchar(' ');
		print_hexa_content(addr, i, size);
		print_content(addr, i, size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
