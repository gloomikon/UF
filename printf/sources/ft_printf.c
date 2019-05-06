/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:34:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/06 19:53:56 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int ft_printf(const char *format, ...)
{
	t_printf_struct ps;

	ft_bzero(&ps, sizeof(ps));
	ps.format = (char *)format;
	va_start(ps.ap, format);
	while (*ps.format)
	{
		if (*ps.format == '%')
		{
			++ps.format;
			if (!*ps.format || (*ps.format == ' ' && (!ps.format[1] ||
				(!ps.format[2] && ps.format[1] == 'h'))))
				break ;
			ft_parse_all(&ps);
		}
		else
			//ft_buffering(&ps, ps.format, 1);
			++ps.format;
	}
	write(1, ps.buff, ps.buff_index);
	va_end(ps.ap);
	return (ps.length);
}