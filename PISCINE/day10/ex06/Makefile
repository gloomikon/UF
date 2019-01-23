# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 16:36:40 by mzhurba           #+#    #+#              #
#    Updated: 2018/07/24 14:25:44 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DO_O_P
FILES_C = ft_putchar.c ft_putstr.c ft_putnbr.c ft_atoi.c operations.c do_op.c
FILES_O = ft_putchar.o ft_putstr.o ft_putnbr.o ft_atoi.o operations.o do_op.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES_C)
	gcc -Wall -Wextra -Werror -o do-op $(FILES_O)

clean	:
	rm -f *.o do-op
