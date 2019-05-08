/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:10:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/06 19:40:13 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_parse_flags(t_printf_struct *ps)
{
	while ((ps->n = ft_strchri("# +-0*", *ps->format, -1)) > -1 && ++ps->format)
		ps->f |= (1 << ps->n);
	(ps->f & FL_MINUS) ? ps->f &= ~FL_ZERO : 0;
	(ps->f & FL_PLUS) ? ps->f &= ~FL_SPACE : 0;
	if (ps->f & WP_WILDCARD)
	{
		ps->f &= ~WP_WILDCARD;
		if ((ps->n = (int)va_arg(ps->ap, int)) < 0)
		{
			ps->f |= FL_MINUS;
			ps->n *= -1;
		}
		if (!(ps->f & APP_PRECI))
			ps->min_length = ps->n;
		else
		{
			ps->precission = (!(ps->f & FL_MINUS)) ? ps->n : 0;
			ps->f = (!ps->n) ? ps->f | APP_PRECI : ps->f & ~APP_PRECI;
		}
	}
}