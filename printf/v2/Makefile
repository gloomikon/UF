# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 14:57:34 by mzhurba           #+#    #+#              #
#    Updated: 2019/06/25 15:13:12 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	check_digit_prec.c\
		check_digit_sign.c\
		check_settings.c\
		ft_printf.c\
		get_flag.c\
		get_mod.c\
		get_precision.c\
		get_spec.c\
		get_tag.c\
		get_width.c\
		init_char_arg.c\
		init_flag.c\
		init_int_arg.c\
		init_str_arg.c\
		init_wchar_arg.c\
		init_wstr_arg.c\
		print_char_width.c\
		print_char.c\
		print_conversion.c\
		print_digit_sign.c\
		print_digit_width.c\
		print_digit.c\
		print_null_char.c\
		print_null_str.c\
		print_str_width.c\
		print_str.c\
		print_wchar_minus.c\
		print_wchar.c\
		print_wstr_minus.c\
		print_wstr.c\
		put_wc.c\
		put_wchar.c\
		put_wstr_c.c\
		put_wstr.c\
		spec_char.c\
		spec_int.c\
		spec_percent.c\
		spec_unsint.c\
		spec_wchar.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = clang
CFLAGS = -c -Wall -Wextra -g  #-Werror

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
	@make -C ./libft fclean 
	@echo "[ft_printf - fclean]"

re: fclean all
