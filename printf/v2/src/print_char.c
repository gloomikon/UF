/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:18:36 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 20:18:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_char(t_pf_env *e, char c)
{
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, &c, 1);
		print_char_width(e);
	}
	else
	{
		print_char_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
