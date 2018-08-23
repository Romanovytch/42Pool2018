# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 21:17:16 by flgivern          #+#    #+#              #
#    Updated: 2018/08/19 19:02:21 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= colle-2

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c			\
			  error.c			\
			  rush_maker.c		\
			  ft_read.c			\
			  ft_putchar.c		\
			  ft_putstr.c		\
			  ft_strncpy.c		\
			  ft_strcmp.c		\
			  ft_putnbr.c

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
