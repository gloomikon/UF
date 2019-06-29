/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:32:49 by marvin            #+#    #+#             */
/*   Updated: 2019/06/29 19:32:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_base_width(t_pf_env *e, char type)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(e->out);
	if ((e->flag.f & F_HASH) && (e->out[0] != '\0' && e->out[0] != '0'))
	{
		e->flag.width -= ((type == 'o' || type == 'O') ? 1 : 0);
		e->flag.width -= ((type == 'x' || type == 'X') ? 2 : 0);
	}
	if (e->flag.prec >= 0)
	{
		while (e->flag.width > e->flag.prec + ++i && e->flag.width > len + i)
			e->ret += write(e->fd, " ", 1);
		while (e->flag.width > len + i++)
			e->ret += write(e->fd, "0", 1);
	}
	else
	{
		while (e->flag.width > len + ++i)
			e->ret += (e->flag.f & F_ZERO ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
	}
}
