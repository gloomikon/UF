/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_unsint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:43:10 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 16:43:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_unsint(t_pf_env *e, char t)
{
	long tmp;

	e->flag.f &= ~F_SPACE;
	e->flag.f &= ~F_PLUS;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (t == 'D' || t == 'U' || (e->flag.f & SM_Z) || (e->flag.f & SM_L) ||
			(e->flag.f & SM_T) || (e->flag.f & SM_J) || (e->flag.f & SM_LL))
		e->out = ft_ultoa((unsigned long)tmp);
	else if (e->flag.f & SM_H)
		e->out = ft_ultoa((unsigned short)tmp);
	else if (e->flag.f & SM_HH)
		e->out = ft_ultoa((unsigned char)tmp);
	else if ((e->flag.f & SM_NO_MOD) && t != 'U')
		e->out = ft_ultoa((unsigned int)tmp);
	print_digit(e);
}
