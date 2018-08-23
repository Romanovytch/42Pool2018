# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 21:17:16 by flgivern          #+#    #+#              #
#    Updated: 2018/08/09 10:45:47 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_advanced_do-op

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c		\
			  do_op.c		\
			  operations.c	\
			  error.c		\
			  ft_putstr.c	\
			  ft_atoi.c		\
			  ft_strlen.c	\
			  ft_putnbr.c	\
			  ft_putchar.c	\
			  ft_strcmp.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I.

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
