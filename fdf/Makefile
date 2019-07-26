# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 21:56:49 by mzhurba           #+#    #+#              #
#    Updated: 2019/07/26 03:59:08 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	auxiliary.c colorizer.c drawing.c keyboard.c main.c read.c\
		change_view.c displaying.c free.c lst.c menu.c transformation.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes
LIBS = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

CC = clang
CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS) | lib
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "💾  [fdf - ready] 💾"

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
	@echo "🗑  [fdf - fclean] 🗑"


re: fclean all