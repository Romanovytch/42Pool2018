# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 21:17:16 by flgivern          #+#    #+#              #
#    Updated: 2018/08/19 22:41:57 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= evalexpr

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c					\
			  operations.c				\
			  priority.c				\
			  ft_create_elem.c			\
			  ft_list_push_back.c		\
			  ft_list_pop.c				\
			  ft_list_last.c			\
			  ft_list_getindex.c		\
			  ft_list_remove_index.c	\
			  ft_list_insert_index.c	\
			  ft_list_size.c			\
			  ft_evalexpr.c				\
			  ft_atoi.c					\
			  ft_putnbr.c				\
			  ft_putchar.c				\
			  ft_compact.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
