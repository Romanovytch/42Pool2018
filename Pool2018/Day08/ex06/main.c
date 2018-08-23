/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:56:00 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/09 12:01:39 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

struct s_stock_par		*ft_param_to_tab(int ac, char **av);
void					ft_show_tab(struct s_stock_par *tab);

int	main(int argc, char **argv)
{
	ft_show_tab(ft_param_to_tab(argc, argv));
	return (0);	
}
