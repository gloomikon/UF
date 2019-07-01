/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptraddr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:10:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 16:10:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_ptraddr(t_pf_env *e, char type)
{
	if ((e->flag.f & F_ZERO) && e->flag.prec == -1)
		e->flag.prec = e->flag.width - 2;
	if (ft_strcmp(e->out, "(nil)"))
		ptraddr_prec(e);
	if (type == 'p')
		ft_strlower(e->out);
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_ptraddr_width(e);
	}
	else
	{
		print_ptraddr_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
