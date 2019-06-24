/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_str_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:36:46 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 18:36:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_str_arg(t_pf_env *e, char **tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], char *);
	}
	else
		*tmp = va_arg(e->ap[0], char *);
}
