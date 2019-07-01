/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:39:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 11:39:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_precision(t_pf_env *e, char type)
{
	double		d;
	long double	ld;

	if (e->flag.f & SM_BIG_L)
	{
		init_long_double(e, &ld);
		if (ld != ld || (ld * 2 == ld && ld != 0))
			return (nan_inf(e, type, ld));
	}
	else
	{
		init_prec_arg(e, &d);
		if (d != d || (d * 2 == d && d != 0))
			return (nan_inf(e, type, d));
		ld = (long double)d;
	}
	if (type == 'e' || type == 'E')
		return (print_prec_e(e, ld, type));
	if (type == 'f' || type == 'F')
		return (print_prec_f(e, ld));
	// if (type == 'g' || type == 'G')
	// 	return (print_prec_g(e, ld, type));
	// if (type == 'a' || type == 'A')
	// 	return (print_prec_a(e, ld, type));
}