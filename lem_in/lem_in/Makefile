# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 17:27:21 by mzhurba           #+#    #+#              #
#    Updated: 2019/08/20 19:22:58 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	ants.c auxiliary.c comb_funcs.c displaying_result.c lists_funcs.c\
		main.c reading.c saving_input.c validation.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
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
	@echo "💾  [lem-in - ready] 💾"

lib:
	@make -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@echo "🗑  [lem-in - fclean] 🗑"


re: fclean all
