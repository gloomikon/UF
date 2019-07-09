# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/26 22:56:20 by mzhurba           #+#    #+#              #
#    Updated: 2018/07/26 22:56:23 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat 

HEADER = mylib.h

FILES_C = *.c 

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I$(HEADER) $(FILES_C) 
	gcc -Wall -Wextra -Werror *.o -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

