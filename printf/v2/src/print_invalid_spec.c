/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:30:31 by marvin            #+#    #+#             */
/*   Updated: 2019/06/30 15:30:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_invalid_spec(t_pf_env *e, char c)
{
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, &c, 1);
		print_invalid_width(e);
	}
	else
	{
		print_invalid_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
