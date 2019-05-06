/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:09:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/06 19:40:44 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

# define MAX(x, y)		(x - ((x - y) & ((x - y) >> 31)))
# define MIN(x, y)		(y + ((x - y) & ((x - y) >> 31)))
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a
# define STRERR			strerror

# define FL_HASHTAG		(1 << 0)
# define FL_SPACE		(1 << 1)
# define FL_PLUS			(1 << 2)
# define FL_MINUS		(1 << 3)
# define FL_ZERO			(1 << 4)
# define WP_WILDCARD		(1 << 5)
# define IS_UPCASE		(1 << 6)
# define L_SHORT		(1 << 7)
# define L_SHORT2		(1 << 8)
# define L_LONG			(1 << 9)
# define L_LONG2		(1 << 10)
# define L_INTMAX		(1 << 11)
# define L_SIZE_T		(1 << 12)

# define MIN_LEN		(1 << 13)
# define APP_PRECI	(1 << 14)
# define POINTER		(1 << 15)
# define PF_BUFF_SIZE	64

typedef struct	s_printf
{
	int			length;
	short		f;
	short		n;
	int			min_length;
	int			precission;
	int			padding;
	//int fd;
	int			buff_index;
	char		buff[PF_BUFF_SIZE];
	va_list		ap;
	char		*format;
	unsigned	c;
}				t_printf_struct;

short	ft_strchri(char *str, int c, int i);
void	ft_parse_flags(t_printf_struct *ps);

#endif