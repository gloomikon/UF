/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:22:12 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 14:06:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_printf(const char *restrict format, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	va_start(e.ap[0], format);
	va_copy(e.ap[1], e.ap[0]);
	while (format[e.i])
	{
		if (format[e.i] == '{')
			check_settings(format, &e);
		else if (format[e.i] == '%' && format[e.i + 1] != '%')
			print_conversion(format, &e);
		else if (format[e.i] == '%' && format[e.i + 1] == '%')
		{
			e.ret += write(e.fd, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(e.fd, &format[e.i++], 1);
	}
	va_end(e.ap[0]);
	return (e.ret);
}
