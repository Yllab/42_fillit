# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/23 17:08:45 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	input_generator

SRCS		=	*.c

INCLUDES	=   ../libft/includes/

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

all			:	$(NAME)

$(NAME)		:	$(OBJS) lib
				$(CC) $(CFLAGS) -o $@ -L ../libft/ -lft $(OBJS)

lib			:	
				make -C ../libft/

loop		:
				number=1 ; while [[ $$number -le 100 ]] ; do \
        			((number = number + 1)) ; \
    			done

noflags		:	
				$(CC) -o $(NAME) -I $(INCLUDES) -L ../libft/ -lft $(SRCS) 

%.o			:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $^

clean		:
				rm -f $(OBJS)
				rm *.gch

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
