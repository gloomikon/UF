# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 21:56:49 by mzhurba           #+#    #+#              #
#    Updated: 2019/07/16 22:43:09 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mzhurba.filler

SRC =	check_dr.c cr_point.c get_left.c init_corner.c main.c read_piece.c\
		check_map.c get_player.c right_side.c\
		check_ul.c fit_piece.c get_right.c invalid_pos.c read_data.c\
		check_valid.c get_bottom.c get_top.c left_side.c read_map.c\
		piece_fill_right.c piece_fill_left.c piece_put_down.c\
		piece_put_right.c piece_put_left.c piece_put_up.c free_all.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = objSRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes
LIBS = -L libft/ -lft

CC = clang
CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS) | lib
	@$(CC) $(OBJS) $(LIBS) -o $@
	@make -C ./visualizer
	@echo "💾  [mzhurba.filler - ready] 💾"

lib:
	@make -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C ./libft clean
	@make -C ./visualizer clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@make -C ./visualizer fclean
	@echo "🗑  [mzhurba.filler - fclean] 🗑"


re: fclean all