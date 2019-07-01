/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:44:11 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 11:44:11 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_prec_e(t_pf_env *e, long double d, char type)
{
	ftoa_prec_e(e, d, type);
	if (e->flag.f & F_MINUS)
	{
		if (d > 0 && (e->flag.f & (F_PLUS | F_SPACE)))
			e->ret += (e->flag.f & F_PLUS ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_prec_width(e);
	}
	else
	{
		print_prec_width(e);
		if (d > 0 && (e->flag.f & (F_PLUS | F_SPACE)))
			e->ret += (e->flag.f & F_SPACE ? write(e->fd, "+", 1) :
			write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
