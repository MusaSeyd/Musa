# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcelesti <fcelesti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 19:39:42 by hfast             #+#    #+#              #
#    Updated: 2022/03/12 17:47:16 by fcelesti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME2	=	checker

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

FILES	=	push_swap.c big_sort.c	check_validation.c	finding_place.c\
			functions.c	functions_2.c	functions_3.c	initialization.c\
			libft.c		quick_sort.c	separation.c	sort_3_and_5.c\
			split.c

FILES2	=	bonus/checker.c		bonus/get_next_line.c	check_validation.c	functions.c\
			functions_2.c	functions_3.c	quick_sort.c		separation.c\
			initialization.c	libft.c		bonus/get_next_line_utils.c split.c
		

OBJS	=	$(FILES:%.c=%.o)

OBJS2	=	$(FILES2:%.c=%.o)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME2): $(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -o $(NAME2)

all: $(NAME)

bonus: $(NAME2)

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
