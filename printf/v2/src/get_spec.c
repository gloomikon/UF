/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:52:24 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 17:29:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void get_spec_2(const char *restrict format, t_pf_env *e)
{
	if (ft_strchr(HEX, format[e->i]))
		spec_base(e, format[e->i]);
// 	else if (format[e->i] == 'n')
// 		spec_return(e);
	else if (format[e->i] == 'p' || format[e->i] == 'P')
		spec_ptraddr(e, format[e->i]);
// 	else if (format[e->i] == 'r')
// 		spec_non_printable(e);
// 	else if (format[e->i] == 'w')
// 		spec_fd(e);
// 	else if (format[e->i] == 'q')
// 		print_dice(e);
	// else if (format[e->i] != '\0')
	// 	print_invalid_spec(e, format[e->i]);
	else e->ret += write(e->fd, "%", 1);
}

void	get_spec(const char *restrict format, t_pf_env *e)
{
	if (IS_PER(format[e->i]))
		spec_percent(e);
	else if (IS_INT(format[e->i]) && !(e->flag.f & SM_Z))
		spec_int(e);
	else if (IS_UINT(format[e->i]) || (IS_INT(format[e->i]) &&
	(e->flag.f & SM_Z)))
		spec_unsint(e, format[e->i]);
	else if (IS_SCHR(format[e->i]) && !(e->flag.f & SM_L))
		spec_char(e, format[e->i]);
	else if (IS_BSCHR(format[e->i]))
		spec_char(e, format[e->i] + 32);
	else if (IS_SCHR(format[e->i]) && (e->flag.f & SM_L))
		spec_wchar(e, format[e->i]);
	else if (ft_strchr(PREC, format[e->i]))
		spec_precision(e, format[e->i]);
	else
		get_spec_2(format, e);
}
