# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/06 18:31:50 by tpokalch          #+#    #+#              #
#    Updated: 2019/01/06 18:51:11 by tpokalch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	make -C libft/ fclean && make -C libft/
	clang -g -Wall -Wextra -Werror -I libft/includes -o put_piece.o -c put_piece.c	
	clang -g -Wall -Wextra -Werror -I libft/includes -o fit.o -c fit.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o big_fit.o -c big_fit.c	
	clang -g -Wall -Wextra -Werror -I libft/includes -o create_list.o -c create_list.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o next_legal_slot.o -c next_legal_slot.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o erase_piece.o -c erase_piece.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o initialize_square.o -c initialize_square.c	
	clang -g -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o fillit main.o put_piece.o fit.o next_legal_slot.o create_list.o erase_piece.o big_fit.o initialize_square.o -I libft/includes -L libft/ -lft
	
clean:
	rm -r *.o
