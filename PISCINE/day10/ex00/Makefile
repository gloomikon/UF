# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 17:07:05 by mzhurba           #+#    #+#              #
#    Updated: 2018/07/24 17:08:26 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = $(S)ft_putchar.c $(S)ft_putstr.c $(S)ft_strcmp.c $(S)ft_strlen.c $(S)ft_swap.c
OBJECTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
S = ./srcs/
I = ./includes/
HEAD = ft.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(FILES) $(I)$(HEAD)
	ar rc $@ $(OBJECTS)
	ranlib $@  

clean:
	rm -f $(OBJECTS) $(I)$(HEAD).gch

fclean: clean
	rm -f $(NAME)

re: fclean all
