# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 12:22:06 by mmahloko          #+#    #+#              #
#    Updated: 2018/08/05 12:36:44 by mmahloko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfiller.a

OPT = -c

CFLAGS = -Wall -Wextra -Werror

SRC = moves.c filler.c place_piece.c ai.c trimming.c resetting.c

OBJ = moves.o filler.o place_piece.o ai.o trimming.o resetting.o

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(OPT) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc libfiller.a libft/libft.a -o filler

clean :
	@make clean -C libft
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(NAME)

fclean : clean
	@make fclean -C libft
	@/bin/rm -f filler
re: fclean all

n :
	make n -C libft
	norminette *.c
	norminette filler.h
