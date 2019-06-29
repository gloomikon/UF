/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base_pre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:30:05 by marvin            #+#    #+#             */
/*   Updated: 2019/06/29 19:30:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_base_pre(t_pf_env *e, char type, long val)
{
	if ((e->flag.f & F_HASH) && e->out[0] != '\0' && val != 0)
	{
		e->ret += (type == 'o' || type == 'O') ? write(e->fd, "0", 1) : 0;
		e->ret += (type == 'x') ? write(e->fd, "0x", 2) : 0;
		e->ret += (type == 'X') ? write(e->fd, "0X", 2) : 0;
		type == 'a' || type == 'A' ? e->flag.width -= 2 : 0;
	}
	else if ((type == 'o' || type == 'O') && (e->flag.f & F_HASH) &&
			e->flag.prec >= 0)
		e->ret += write(e->fd, "0", 1);
	else if (type == 'a' || type == 'A')
	{
		if (e->flag.f & (F_PLUS | F_SPACE))
		{
			e->ret += e->flag.f & F_SPACE ? write(1, " ", 1) : write(1, "+", 1);
			e->flag.width--;
		}
		e->ret += type == 'a' ? write(e->fd, "0x", 2) : write(e->fd, "0X", 2);
		e->flag.width -= 2;
	}
}
