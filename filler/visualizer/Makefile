# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 19:47:51 by mzhurba           #+#    #+#              #
#    Updated: 2019/07/15 20:00:01 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

SRC =	colorizer.c end_free.c init_map.c init_score_meter.c init_winner.c\
        print_one_line.c update.c update_score_meter.c create_score_line.c\
		init_header.c init_players.c init_screen.c read_size.c update_map.c\
		main.c
OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes -I ../libft/ft_printf/includes
LIBS = -lncurses -lft -L ../libft

CC = clang

CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all