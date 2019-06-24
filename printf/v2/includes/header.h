/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:04:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/24 20:40:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# include "../libft/libft.h"

# define FLAGS		" #+-*.0123456789Lhjltz"
# define HEX		"boxBOX"
# define PREC		"fageFAGE"

# define IS_NUM(x)		(x >= '0' && x <= '9')
# define IS_PNUM(x)		(x >= '1' && x <= '9')

# define IS_PER(x)		(x == '%')
# define IS_INT(x)		(x == 'd' || x == 'i')
# define IS_UINT(x)		(x == 'u' || x == 'U' || x == 'D')
# define IS_SCHR(x)		(x == 'c' || x == 's')
# define IS_BSCHR(x)	(x == 'C' || x == 'S')

/*
** This is used to save flags " #+-0" and either number is nrgative
*/

# define F_HASH		(1 << 0)
# define F_SPACE	(1 << 1)
# define F_PLUS		(1 << 2)
# define F_MINUS	(1 << 3)
# define F_ZERO		(1 << 4)
# define F_NEGATIVE (1 << 5)

/*
** This is used to save size modifiers
*/

# define SM_NO_MOD	(1 << 7)
# define SM_LL		(1 << 8)
# define SM_HH		(1 << 9)
# define SM_BIG_L	(1 << 10)
# define SM_H		(1 << 11)
# define SM_J		(1 << 12)
# define SM_L		(1 << 13)
# define SM_T		(1 << 14)
# define SM_Z		(1 << 15)


typedef struct		s_pf_flag
{
	uint16_t		f;
	int				prec;
	int				width;
}					t_pf_flag;

typedef struct		s_pf_env
{
	va_list			ap[2];
	char			*out;
	int				tag;
	t_pf_flag		flag;
	int				fd;
	int				i;
	int				ret;
}					t_pf_env;

int					ft_printf(const char *restrict format, ...);

void				check_settings(const char *restrict fmt, t_pf_env *e);

void				get_tag(const char *restrict format, t_pf_env *e);
void				get_flag(const char *restrict format, t_pf_env *e);
void				get_spec(const char *restrict format, t_pf_env *e);
void				get_mod(const char *restrict format, t_pf_env *e);
void				get_width(t_pf_env *e);
void				get_precision(const char *restrict format, t_pf_env *e);


void				init_flag(t_pf_flag *flag);
void				init_int_arg(t_pf_env *e, long *tmp);
void				init_str_arg(t_pf_env *e, char **tmp);
void				init_char_arg(t_pf_env *e, int *tmp);

void				print_conversion(const char *restrict format, t_pf_env *e);
void				print_digit(t_pf_env *e);
void				print_digit_sign(t_pf_env *e);
void				print_digit_width(t_pf_env *e); //?
void				print_str(t_pf_env *e);
void				print_null_str(t_pf_env *e);
void				print_str_width(t_pf_env *e);
void				print_char(t_pf_env *e, char c);
void				print_char_width(t_pf_env *e);

void				check_digit_sign(t_pf_env *e);
void				check_digit_prec(t_pf_env *e);

/*
** Output functions
*/

void				spec_percent(t_pf_env *e);
void				spec_int(t_pf_env *e);
void				spec_unsint(t_pf_env *e, char t);
void				spec_char(t_pf_env *e, char type);

#endif
