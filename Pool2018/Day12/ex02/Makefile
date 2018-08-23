# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 21:17:16 by flgivern          #+#    #+#              #
#    Updated: 2018/08/20 17:22:15 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_tail

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c			\
			  error.c			\
			  ft_tail.c			\
			  ft_strncpy.c		\
			  ft_atoi.c			\
			  ft_putstr.c		\
			  ft_putchar.c		\
			  ft_read.c

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
