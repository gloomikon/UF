/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:04:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/13 14:03:24 by mzhurba          ###   ########.fr       */
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

# define IS_NUM(x)	(x >= '0' && x <= '9')
# define IS_PNUM(x)	(x >= '1' && x <= '9')

# define IS_PER(x)	(x == '%')
# define IS_INT(x)	(x == 'd' || x == 'i')
# define IS_UINT(x)	(x == 'u' || x == 'U' || x == 'D')
# define IS_SCHR(x)	(x == 'c' || x == 's')
# define IS_BCHAR(x)	(x == 'C' || x == 'S')

/*
** This is used to save flags " #+-0"
*/

# define F_HASH		(1 << 0)
# define F_SPACE	(1 << 1)
# define F_PLUS		(1 << 2)
# define F_MINUS	(1 << 3)
# define F_ZERO		(1 << 4)

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

typedef struct		s_pf_tag
{
	int				tag;
	int				pos;
}					t_pf_tag;

typedef struct		s_pf_flag
{
	uint16_t		f;
	int				neg;
	int				prec;
	int				width;
}					t_pf_flag;

typedef struct		s_pf_env
{
	va_list			ap[2];
	char			*out;
	t_pf_tag		tag;
	t_pf_flag		flag;
	int				fd;
	int				i;
	int				ret;
}					t_pf_env;

int					ft_printf(const char *restrict format, ...);
void				print_conversion(const char *restrict format, t_pf_env *e);
void				get_tag(const char *restrict format, t_pf_env *e);
void				get_flag(const char *restrict format, t_pf_env *e);
void				get_mod(const char *restrict format, t_pf_env *e);
void				get_width(t_pf_env *e);
void				get_precision(const char *restrict format, t_pf_env *e);
void				get_spec(const char *restrict format, t_pf_env *e);
void				init_flag(t_pf_flag *flag);

#endif
