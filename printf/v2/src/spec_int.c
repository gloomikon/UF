/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:53:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 18:42:38 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_int(t_pf_env *e)
{
	long tmp;
	long i;

	init_int_arg(e, &tmp);
	i = (long long)tmp;
	(e->flag.f & F_MINUS) ? e->flag.f &= ~F_ZERO : 0;
	(e->flag.prec >=0) ? e->flag.f &= ~F_ZERO : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (e->flag.f & SM_HH)
		e->out = ft_itoa((char)i);
	else if (e->flag.f & SM_H)
		e->out = ft_itoa((short)i);
	// else if ((e->flag.f & SM_L) || (e->flag.f & SM_T) ||
	// 		(e->flag.f & SM_LL) || (e->flag.f & SM_J))
	// 	e->out = ft_ltoa((long)i);
	else if (e->flag.f & SM_NO_MOD)
		e->out = ft_itoa((int)i);
	print_digit(e);
}
