# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 17:44:11 by csantacr          #+#    #+#              #
#    Updated: 2023/03/23 18:25:23 by csantacr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

SRC =	ft_printf.c\
		ft_printf_tools/ft_putchar.c\
		ft_printf_tools/ft_puthex.c\
		ft_printf_tools/ft_putlonghex.c\
		ft_printf_tools/ft_putnbr.c\
		ft_printf_tools/ft_putstr.c\
		ft_printf_tools/ft_putunbr.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
