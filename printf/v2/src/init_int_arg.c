/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_int_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:46:48 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 16:53:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_int_arg(t_pf_env *e, long *tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], long);
	}
	else
		*tmp = va_arg(e->ap[0], long);
}
