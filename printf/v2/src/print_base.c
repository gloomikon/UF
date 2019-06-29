/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 17:53:14 by marvin            #+#    #+#             */
/*   Updated: 2019/06/28 17:53:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_base(t_pf_env *e, char type, long val)
{
	check_base_prec(e, type);
	if (e->flag.f & F_ZERO)
	{
		print_base_pre(e, type, val);
		print_base_width(e, type);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.f & F_MINUS)
	{
		print_base_pre(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_base_width(e, type);
	}
	else
	{
		print_base_width(e, type);
		print_base_pre(e, type, val);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
