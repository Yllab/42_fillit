# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/24 17:21:32 by hbally           ###   ########.fr        #
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

$(NAME)		:	$(OBJS) compile_lib
				$(CC) -o $@ $(CFLAGS) $(LIB) $(OBJS)

test		:	$(OBJS) compile_lib
				$(CC) -o ./tests/maintest.o $(CFLAGS) $(INCLUDES) -c ./tests/maintest.c
				$(CC) -o ./tests/test $(CFLAGS) $(LIB) $(OBJS) ./tests/maintest.o
				make -C ./input_generator/
				./input_generator/input_generator -r > ./tests/randominput
				./tests/test randominput

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
				rm -f ./tests/randominput
				rm -f $(NAME)

re			:	fclean all
