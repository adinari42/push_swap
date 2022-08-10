# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adinari <adinari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 01:20:12 by adinari           #+#    #+#              #
#    Updated: 2022/08/10 06:49:34 by adinari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

OBJ_PATH_BONUS = ./bonus/

FILES = push_swap.c\
		llist_ctrl.c\
		check_functions.c\
		sorting_funct.c\
		sorting_funct2.c\
		utils.c\
		ft_split.c\
		dupsort_check.c\
		extra.c\
		push_chunk_utils.c\
		push_back_forth.c\
		sorted_list.c\

BONUS_FILES =	checker.c\
				get_next_line_utils.c\
				get_next_line.c\
				bonus_sorting_funct.c\
				bonus_sorting_funct2.c\
				ll_ctrl.c\
				dupsort_check.c\
				ft_split.c\
				utils.c\
				check_functions.c\

OBJECTS = $(FILES:.c=.o)
OBJECTS_BONUS = $(BONUS_FILES:.c=.o)

OBJ_BONUS = $(addprefix $(OBJ_PATH_BONUS), $(OBJECTS_BONUS))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
		$(CC) $(FLAGS) -fsanitize=address $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) *.o

re: fclean all
