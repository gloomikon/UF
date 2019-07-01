/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_long_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:34:48 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 11:34:48 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_long_double(t_pf_env *e, long double *tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], long double);
		return ;
	}
	*tmp = va_arg(e->ap[0], long double);
}
