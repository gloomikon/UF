/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:57:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 17:44:10 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_flag(const char *restrict format, t_pf_env *e)
{
	while (ft_strchr(FLAGS, format[e->i]))
	{
		format[e->i] >= 'L' && format[e->i] <= 'z' ? get_mod(format, e) : 0;
		format[e->i] == ' ' ? e->flag.f |= F_SPACE : 0; // сдвиги влево переписать в одну строку
		format[e->i] == '-' ? e->flag.f |= F_MINUS : 0;
		format[e->i] == '+' ? e->flag.f |= F_PLUS : 0;
		format[e->i] == '#' ? e->flag.f |= F_HASH : 0;
		format[e->i] == '0' ? e->flag.f |= F_ZERO : 0;
		format[e->i] == '*' ? get_width(e) : 0;
		if (format[e->i] == '.')
			get_precision(format, e);
		else if (IS_PNUM(format[e->i]) && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(format + e->i);
			while (IS_NUM(format[e->i]))
				++e->i;
		}
		else
			++e->i;
	}
}
