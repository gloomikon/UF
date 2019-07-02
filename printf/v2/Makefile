# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 14:57:34 by mzhurba           #+#    #+#              #
#    Updated: 2019/07/02 19:09:13 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	check_base_prec.c\
		check_digit_prec.c\
		check_digit_sign.c\
		check_form.c\
		check_settings.c\
		delete_zero.c\
		ft_printf.c\
		ft_str_prec.c\
		ftoa_prec_e.c\
		ftoa_prec_eg.c\
		ftoa_prec_f.c\
		ftoa_prec_fg.c\
		get_exponent.c\
		get_flag.c\
		get_mod.c\
		get_prec_num_e.c\
		get_prec_num_f.c\
		get_precision.c\
		get_spec.c\
		get_tag.c\
		get_width.c\
		init_char_arg.c\
		init_flag.c\
		init_int_arg.c\
		init_long_double.c\
		init_prec_arg.c\
		init_str_arg.c\
		init_wchar_arg.c\
		init_wstr_arg.c\
		nan_inf.c\
		print_base_pre.c\
		print_base_width.c\
		print_base.c\
		print_char_width.c\
		print_char.c\
		parse_and_print.c\
		print_digit_sign.c\
		print_digit_width.c\
		print_digit.c\
		print_invalid_spec.c\
		print_invalid_width.c\
		print_null_char.c\
		print_prec_e.c\
		print_prec_f.c\
		print_prec_g.c\
		print_prec_width.c\
		print_ptraddr_width.c\
		print_ptraddr.c\
		print_str_width.c\
		print_str.c\
		print_wchar_minus.c\
		print_wchar.c\
		print_wstr_minus.c\
		print_wstr.c\
		ptraddr_prec.c\
		put_wc.c\
		put_wchar.c\
		put_wstr_c.c\
		put_wstr.c\
		spec_base.c\
		spec_char.c\
		spec_int.c\
		spec_non_printable.c\
		spec_percent.c\
		spec_precision.c\
		spec_ptraddr.c\
		spec_return.c\
		spec_unsint.c\
		spec_wchar.c

OBJ = $(SRC:.c=.o)

SRCDIR = src
OBJDIR = obj

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = clang
CFLAGS = -c -Wall -Wextra -g -fPIC #-Werror

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
