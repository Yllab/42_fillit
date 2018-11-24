# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/24 19:35:11 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRCS		=	./srcs/print_tetro.c \
				./srcs/convert_tetro.c \
				./srcs/get_next_line.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=   -I ./libft/includes \
				-I ./includes

LIB			=	-L ./libft/ -lft

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

all			:	$(NAME)

#REMOVE MAIN.O AND ADD TO SOURCES ONCE TESTING IS OVER
$(NAME)		:	$(OBJS) compile_lib
				$(CC) -o ./srcs/main.o $(CFLAGS) $(INCLUDES) -c ./srcs/main.c
				$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJS) ./srcs/main.o

test		:	$(NAME)
				$(CC) -o ./tests/maintest.o $(CFLAGS) $(INCLUDES) -c ./tests/maintest.c
				$(CC) -o ./tests/test $(CFLAGS) $(LIB) $(OBJS) ./tests/maintest.o
				cp ./fillit ./tests/
				
runtest		:	
				clear
				./tests/test randominput | less

runfillit	:	
				clear
				./fillit ./tests/randominput | less

input		:	
				make -C ./input_generator/
				./input_generator/input_generator -r > ./tests/randominput

compile_lib	:	
				make -C ./libft/

%.o			:	%.c
				$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $^

clean		:
				make clean -C ./libft/
				make clean -C ./input_generator/
				rm -f $(OBJS)
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
