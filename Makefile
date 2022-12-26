# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022-12-26 21:42:40 by mkostenk          #+#    #+#              #
#    Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SOURCE= ft_checkformat.c ft_converthex.c ft_convertint.c ft_convertptr.c ft_convertuns.c	\
	ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c ft_printptr.c ft_printstr.c	\
	ft_printuns.c ft_strchr.c ft_strlen.c

OBJ=$(SOURCE:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all:$(NAME)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all
