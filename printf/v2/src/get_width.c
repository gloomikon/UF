/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:06:24 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/09 17:08:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_width(t_pf_env *e)
{
	e->flag.width = va_arg(e->ap[0], int);
	if (e->flag.width < 0)
	{
		e->flag.width = -e->flag.width;
		e->flag.f |= F_MINUS;
	}
}
