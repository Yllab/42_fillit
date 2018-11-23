# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/11/23 16:49:30 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRCS		=	./srcs/*.c

INCLUDES	=   ./libft/includes/
				./includes/

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra

CC			=	gcc

all			:	$(NAME)

$(NAME)		:	$(OBJS) lib
				$(CC) $(CFLAGS) -o $@ -L ./libft/ -lft $(OBJS)

lib			:	
				make -C ./libft/

loop		:
				number=1 ; while [[ $$number -le 100 ]] ; do \
					 TEST HERE	\
        			((number = number + 1)) ; \
    			done

%.o			:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $^

clean		:
				rm -f $(OBJS)
				rm *.gch

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
