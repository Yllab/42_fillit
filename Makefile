# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/12/12 15:56:21 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRCS		=	./srcs/convert_tetro.c 		\
				./srcs/check_field.c		\
				./srcs/check_tetro.c		\
				./srcs/result.c				\
				./srcs/check_errors.c		\
				./srcs/get_input.c			\
				./srcs/main.c				\

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=   -I libft/includes \
				-I includes

LIBSDIR		=	libft/

LIBS		=	-L libft/ -lft

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C $(LIBSDIR)
				$(CC) -o $@ $(CFLAGS) $(LIBS) $(OBJS)

%.o			:	%.c
				$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $^

clean		:
				make clean -C $(LIBSDIR)
				rm -f $(OBJS) $(DEPS)

fclean		:	clean
				make fclean -C $(LIBSDIR)
				rm -f $(NAME)

re			:	fclean all
