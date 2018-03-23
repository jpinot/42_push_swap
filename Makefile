# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/03/23 13:19:07 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SWAP = push_swap

FLAGS =

SRC_DIR = srcs/

FUNC_DIR = srcs/funct/

CMND_DIR = srcs/comands/

SRTALG_DIR = srcs/sort_alg/

SRC = main.c\
	  push_swap.c\

FUNC = ft_sort.c\
	   ft_lstnew_num.c\
	   ft_stacknew.c\
	   ft_check_side.c\
	   ft_group_one_sort.c\
	   ft_group_sort.c\
	   ft_merge_func.c\

CMND = ft_ss.c\
	  ft_swap.c\
	  ft_push.c\
	  ft_rotate.c\
	  ft_rv_rotate.c\

SRT_ALG = ft_bubble_one.c\
		  ft_bubble_group.c\
		  ft_merge_one.c\

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))

OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))

OBJ_CMND = $(patsubst %.c, $(CMND_DIR)%.o, $(CMND))

OBJ_SRT = $(patsubst %.c, $(SRTALG_DIR)%.o, $(SRT_ALG))

OBJ = $(SRC:.c=.o) $(FUNC:.c=.o) $(CMND:.c=.o) $(SRT_ALG:.c=.o)

all: $(NAME_SWAP)

$(NAME_SWAP): $(OBJ_SRC) $(OBJ_FUNC) $(OBJ_CMND) $(OBJ_SRT)
	$(MAKE) -C libft
	gcc $(FLAGS) -L./libft/ -lft -I./includes $(OBJ) -o $(NAME_SWAP)

%.o : %.c
	gcc $(FLAGS) -I./includes -c $<

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME_SWAP)

re: fclean
	make

.PHONY: all clean fclean re
