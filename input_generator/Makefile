# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/12/05 09:36:03 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	input_generator

SRCS		=	./generate_input.c 	\
				../srcs/print_tetro.c

INCLUDES	=   -I ../libft/includes/	\
				-I ../includes

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

all			:	$(NAME)

$(NAME)		:	$(OBJS) lib
				$(CC) $(CFLAGS) -o $@ -L ../libft/ -lft $(OBJS)

lib			:	
				make -C ../libft/

noflags		:	
				$(CC) -o $(NAME) $(INCLUDES) -L ../libft/ -lft $(SRCS) 

%.o			:	%.c
				$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $^

clean		:
				rm -f $(OBJS)
				rm -f *.gch

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
