# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:00:58 by mzhurba           #+#    #+#              #
#    Updated: 2018/10/24 18:08:28 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HDR		=	mylib.h
CSRC	=	*.c
CC		=	gcc
CF		=	-Wall -Wextra -Werror -c
SRCS	=	./srcs/
INCS	=	./includes/


all:
	$(CC) $(CF) $(SRCS)$(CSRC) -I$(INCS)$(HDR) 
	ar rc libft.a *.o
	ranlib libft.a

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all

