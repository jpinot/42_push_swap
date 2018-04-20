# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/04/20 17:28:18 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SWAP = push_swap

NAME_CHECK = checker

FLAGS =

SRC_DIR = srcs/

FUNC_DIR = srcs/funct/struct/

MRG_DIR = srcs/funct/merge/

BBL_DIR = srcs/funct/bubble/

CMND_DIR = srcs/comands/

SRTALG_DIR = srcs/sort_alg/

SRC = main_ps.c\
	  push_swap.c\

CHECK = main_c.c\
		checker.c\

FUNC = ft_sort_num.c\
	   ft_lstnew_num.c\
	   ft_ret_new.c\
	   ft_del_num.c\
	   ft_del_ret.c\
	   ft_del_stack.c\
	   ft_stack_new.c

MRG = ft_merge_func.c\
	  ft_sort_top_a.c\
	  ft_sort_top_b.c\
	  ft_is_sort.c\
	  ft_merge_b.c\
	  ft_merge_a.c\
	  ft_merge_a_bgn.c\

BBL = ft_check_side.c\
	  ft_group_one_sort.c\
	  ft_group_sort.c

CMND = ft_swap.c\
	   ft_push.c\
	   ft_rotate.c\
	   ft_rv_rotate.c\
	   ft_rr.c\
	   ft_rrr.c\
	   ft_ss.c\

SRT_ALG = ft_bubble_one.c\
		  ft_bubble_group.c\
		  ft_merge_one.c\

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))

OBJ_CHECK = $(patsubst %.c, $(SRC_DIR)%.o, $(CHECK))

OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))

OBJ_MRG = $(patsubst %.c, $(MRG_DIR)%.o, $(MRG))

OBJ_BBL = $(patsubst %.c, $(BBL_DIR)%.o, $(BBL))

OBJ_CMND = $(patsubst %.c, $(CMND_DIR)%.o, $(CMND))

OBJ_SRT = $(patsubst %.c, $(SRTALG_DIR)%.o, $(SRT_ALG))

OBJ = $(SRC:.c=.o) $(FUNC:.c=.o) $(CMND:.c=.o) $(SRT_ALG:.c=.o) $(MRG:.c=.o) $(BBL:.c=.o)

OBJ_C = $(CHECK:.c=.o) $(FUNC:.c=.o) $(CMND:.c=.o) $(SRT_ALG:.c=.o) $(MRG:.c=.o) $(BBL:.c=.o)

all: $(NAME_SWAP) $(NAME_CHECK)

$(NAME_SWAP): $(OBJ_SRC) $(OBJ_FUNC) $(OBJ_CMND) $(OBJ_SRT) $(OBJ_MRG) $(OBJ_BBL)
	$(MAKE) -C libft
	gcc $(FLAGS) -L./libft/ -lft -I./includes $(OBJ) -o $(NAME_SWAP)
%.o : %.c
	gcc $(FLAGS) -I./includes -c $<

$(NAME_CHECK): $(OBJ_CHECK) $(OBJ_FUNC) $(OBJ_CMND) $(OBJ_SRT) $(OBJ_MRG) $(OBJ_BBL)
	$(MAKE) -C libft
	gcc $(FLAGS) -L./libft/ -lft -I./includes $(OBJ_C) -o $(NAME_CHECK)
%.o : %.c
	gcc $(FLAGS) -I./includes -c $<

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME_SWAP) $(NAME_CHECK)

re: fclean
	make

.PHONY: all clean fclean re
