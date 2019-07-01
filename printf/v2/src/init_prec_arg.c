/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prec_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:40:28 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 11:40:28 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_prec_arg(t_pf_env *e, double *tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], double);
	}
	else
		*tmp = va_arg(e->ap[0], double);
}
