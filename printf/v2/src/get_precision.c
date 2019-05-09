/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:09:11 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/09 17:13:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_precision(const char *restrict format, t_pf_env *e)
{
	if (e->flag.prec >= 0)
	{
		++e->i;
		return ;
	}
	if (format[e->i] == '.' && format[e->i + 1] == '*')
	{
		e->flag.prec = va_arg(e->ap[0], int);
		e->i += 2;
	}
	else if (format[e->i] == '.')
	{
		++e->i;
		e->flag.prec = ft_atoi(format + e->i);
		while (IS_NUM(format[e->i]))
			++e->i;
	}
}
