/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flgivern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 23:01:44 by flgivern          #+#    #+#             */
/*   Updated: 2018/08/19 23:27:42 by flgivern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

# define TOKEN 0
# define NUMBER 1

typedef int			t_flag;

typedef struct		s_list
{
	struct s_list	*next;
	char			token;
	int				nb;
	t_flag			id;
}					t_list;

t_list				*ft_create_elem(char token, int nb, t_flag id);
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_remove_index(t_list **begin_list, int index);
void				insert(t_list **begin_list, int index,
		int nb, t_flag id);
void				push(t_list **begin_list, char token, int nb, t_flag id);
void				pop(t_list **begin_list);
int					ft_list_getindex(t_list *begin_list, t_list *elem);
int					ft_list_size(t_list *begin_list);
int					eval_expr(char *str);

#endif
