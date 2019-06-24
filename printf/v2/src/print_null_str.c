/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:41:23 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 18:41:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_null_str(t_pf_env *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		e->ret += (e->flag.f & F_ZERO ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
	e->ret += write(e->fd, "(null)", len);
	++e->i;
}
