# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/03/13 09:36:19 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SWAP = push_swap

FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/

FUNC_DIR = srcs/funct/

SRC = main.c\
	  push_swap.c\

FUNC = ft_sort.c\
	   ft_lstnew_num.c\
	   ft_stacknew.c\

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))

OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))

OBJ = $(SRC:.c=.o) $(FUNC:.c=.o)

all: $(NAME_SWAP)

$(NAME_SWAP): $(OBJ_SRC) $(OBJ_FUNC)
	$(MAKE) -C libft
	gcc $(FLAGS) -L./libft/ -lft -I./includes $(OBJ) -o $(NAME_SWAP)

%.o : %.c
	gcc $(FLAGS) -I./includes -c $<

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean
	make

.PHONY: all clean fclean re
