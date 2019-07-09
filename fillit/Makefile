# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 13:32:44 by mzhurba           #+#    #+#              #
#    Updated: 2019/02/17 18:05:33 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILENAMES = big_fit.c\
            create_vector_from_coords.c \
            invalid_piece.c \
            block_belongs.c \
            delete_list.c \
            main.c \
            block_is_edge.c \
            end_action.c \
            next_legal_slot.c \
            block_touches.c \
            erase_piece.c \
            piece_valid.c \
            check_empty_line.c \
            file_valid.c \
            put_piece.c \
            check_endl.c \
            final_action.c \
            read_piece.c \
            check_full_line.c \
            fit.c \
            square_root.c \
            clear_and_return.c \
            free_square.c \
            vector_from_piece.c \
            count_pieces.c \
            full_line_action.c \
            vectors_equall.c \
            create_list.c \
            initialize_square.c \
            create_node.c \
            int_putstr.c

NAME = fillit

SRCS	=$(addprefix srcs/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I srcs/
CFLAGS	+= -I libft/
LFLAGS	= -L ./libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft

clean:
	@rm -rf build/
	@make -C ./libft clean

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

build:
	@mkdir build/

.PHONY: clean fclean re make all
