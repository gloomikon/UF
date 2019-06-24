/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_char_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:45:22 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 18:45:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_char_arg(t_pf_env *e, int *tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], int);
	}
	else
		*tmp = va_arg(e->ap[0], int);
}
