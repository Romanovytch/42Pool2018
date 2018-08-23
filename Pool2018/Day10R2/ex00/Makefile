# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flgivern <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 14:40:17 by flgivern          #+#    #+#              #
#    Updated: 2018/08/14 03:24:38 by flgivern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= clang

SRCS		= srcs/ft_putchar.c	\
			  srcs/ft_swap.c	\
			  srcs/ft_putstr.c	\
			  srcs/ft_strlen.c	\
			  srcs/ft_strcmp.c

OBJS 		= ft_putchar.o	\
			  ft_swap.o		\
			  ft_putstr.o	\
			  ft_strlen.o	\
			  ft_strcmp.o

INCLUDES 	= -Iincludes/

all: $(NAME)

$(NAME):
	$(CC) -c $(SRCS) $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all
