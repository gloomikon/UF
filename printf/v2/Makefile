# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 14:57:34 by mzhurba           #+#    #+#              #
#    Updated: 2019/06/17 16:25:00 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	check_settings.c\
		ft_printf.c\
		get_flag.c\
		get_mod.c\
		get_precision.c\
		get_spec.c\
		get_tag.c\
		get_width.c\
		init_flag.c\
		print_conversion.c\
		spec_percent.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	@cp ./libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "[ft_printf is ready]"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C ./libft clean 
	@echo "[ft_printf - clean]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[ft_printf - fclean]"

re: fclean all
