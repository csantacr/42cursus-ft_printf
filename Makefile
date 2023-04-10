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

SRC_DIR = src/

OBJ_DIR = obj/

NAME = libftprintf.a

SRC_FILES = 	ft_printf.c\
				ft_printf2.c

SRC = $(addprefix src/, $(addsuffix .c, $(SRC)))

OBJ = $(SRC:.c=.o)

LIBFT = 

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

$(LIBFT) :

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
