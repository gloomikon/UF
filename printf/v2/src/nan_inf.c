/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan_inf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:37:48 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 11:37:48 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	nan_inf(t_pf_env *e, char type, double var)
{
	if (var != var)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "nan", 3);
		else
			e->ret += write(e->fd, "NAN", 3);
	}
	else if (var * 2 == var && var != 0)
	{
		if (type == 'e' || type == 'f' || type == 'g')
			e->ret += write(e->fd, "inf", 3);
		else
			e->ret += write(e->fd, "INF", 3);
	}
	++e->i;
}
