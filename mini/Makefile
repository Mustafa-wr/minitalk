# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 14:44:24 by mradwan           #+#    #+#              #
#    Updated: 2022/10/20 14:44:25 by mradwan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRCS = server.c					\
	   client.c					\
	   minitalk_utils.c 		\
	   ft_printf/ft_printf.c	\
	   ft_printf/ft_supp.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

client:
	gcc  $(CFLAGS) minitalk.a client.c -o client

server:
	gcc  $(CFLAGS) minitalk.a server.c -o server

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	gcc  $(CFLAGS) minitalk.a server.c -o server
	gcc  $(CFLAGS) minitalk.a client.c -o client

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) server client

re: fclean all
