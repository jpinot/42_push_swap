# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/02/26 17:21:22 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SWAP = swap

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

FUNC_DIR = srcs/funct/

SRC = main.c\

FUNC = ft_insertionsort.c\
	   ft_push_stack.c\
	   ft_swap_stack.c\

LIB_SRC = ./libft/ft_strlen.o\
		  ./libft/ft_isdigit.o\
		  ./libft/ft_putstr_fd.o\
		  ./libft/ft_strchr.o\
		  ./libft/ft_strchr.o\
		  ./libft/ft_strcpy.o\
		  ./libft/ft_strdel.o\
		  ./libft/ft_strdup.o\
		  ./libft/ft_strjoin.o\
		  ./libft/ft_strncpy.o\
		  ./libft/ft_strnew.o\
		  ./libft/ft_bzero.o\
		  ./libft/ft_putstr.o\

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))

OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))

OBJ = $(SRC:.c=.o) $(CONV:.c=.o) $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_FUNC)
	@$(MAKE) -C libft
	gcc $(FLAGS) $(OBJ) -Iincludes -L./libft -lfd -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c -Iincludes -Ilibft $<

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
