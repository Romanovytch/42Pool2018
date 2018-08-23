# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 21:17:16 by flgivern          #+#    #+#              #
#    Updated: 2018/08/16 21:17:09 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_hexdump

CC			= clang

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c			\
			  ft_hexdump.c		\
			  ft_strncmp.c		\
			  ft_strndup.c		\
			  ft_putchar.c		\
			  ft_putstr.c		\
			  ft_pow.c

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
