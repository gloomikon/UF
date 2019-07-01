/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:41:03 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 23:41:03 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	spec_return(t_pf_env *e)
{
	int	*tmp;

	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			tmp = va_arg(e->ap[0], int *);
	}
	tmp = va_arg(e->ap[0], int *);
	*tmp = e->ret;
	++e->i;
}