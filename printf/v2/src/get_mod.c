/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:31:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/09 17:04:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_mod(const char *restrict format, t_pf_env *e)
{
	if (!(e->flag.f & SM_NO_MOD)) //not sure if everywhere or not
	{
		if (format[e->i] == 'h' && format[e->i + 1] != 'h')
			e->flag.f |= SM_H;
		else if (format[e->i] == 'h' && format[e->i + 1] == 'h')
		{
			e->flag.f |= SM_HH;
			++e->i;
		}
		else if (format[e->i] == 'l' && format[e->i + 1] != 'l')
			e->flag.f |= SM_L;
		else if (format[e->i] == 'l' && format[e->i + 1] == 'l')
		{
			e->flag.f |= SM_LL;
			++e->i;
		}
		else if (format[e->i] == 'z')
			e->flag.f |= SM_Z;
		else if (format[e->i] == 'j')
			e->flag.f |= SM_J;
		else if (format[e->i] == 'L')
			e->flag.f |= SM_LL;
		else if (format[e->i] == 't')
			e->flag.f |= SM_T;
	}
}
