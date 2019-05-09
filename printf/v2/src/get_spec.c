/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:52:24 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/09 19:35:22 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_spec(const char *restrict format, t_pf_env *e)
{
	if (IS_PER(format[e->i]))
		spec_percent(e);
	else if (IS_INT(format[e->i]) && !(e->flag.f & SM_Z))
		spec_int(e);
	else if ((IS_UINT(format[e->i]) || IS_INT(format[e->i])) &&
	(e->flag.f & SM_Z))
		spec_unsint(e, format[e->i]);
	else if (IS_SCHR(format[e->i]) && !(e->flag.f & SM_L))
		spec_char(e, format[e->i]);
	else if (IS_BCHAR(format[e->i]))
		spec_char(e, format[e->i] + 32);
}