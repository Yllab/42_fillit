# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/29 14:41:52 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

#TODO Remove debug functions
SRCS		=	./srcs/print_tetro.c 		\
				./srcs/print_field.c		\
				./srcs/convert_tetro.c 		\
				./srcs/get_next_line.c 		\
				./srcs/move_tetros_pilot.c	\
				./srcs/move_tetros.c		\
				./srcs/result.c			\
				./srcs/ft_check_errors.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=   -I ./libft/includes \
				-I ./includes

LIB			=	-L ./libft/ -lft

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

TESTDIR		=	tests

all			:	$(NAME)

#TODO Remove main.c/main.o mentions and add main to sources
$(NAME)		:	$(OBJS)
				make -C ./libft/
				$(CC) -o ./srcs/main.o $(CFLAGS) $(INCLUDES) -c ./srcs/main.c
				$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJS) ./srcs/main.o

test		:	$(OBJS)
				make -C ./libft/
				$(CC) -o $@.o $(CFLAGS) $(INCLUDES) -c ./tests/maintest.c
				$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJS) ./tests/maintest.o
				
runtest		:	test	
				clear
				./tests/test randominput

runfillit	:	$(NAME)
				clear
				./fillit ./tests/randominput

input		:	
				make -C ./input_generator/
				./input_generator/input_generator -r > ./tests/randominput

%.o			:	%.c
				$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $^

clean		:
				make clean -C ./libft/
				make clean -C ./input_generator/
				rm -f $(OBJS)
				rm -f ./srcs/main.o
				rm -f ./tests/maintest.o
				rm -f libft/includes/*.gch
				rm -f includes/*.gch

fclean		:	clean
				make fclean -C ./libft/
				make fclean -C ./input_generator/
				rm -f ./tests/test
				rm -f ./tests/fillit
				rm -f ./tests/bad_inputs/fillit
				rm -f ./tests/randominput
				rm -f $(NAME)

re			:	fclean all
