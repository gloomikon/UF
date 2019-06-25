/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:25:24 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 14:25:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_wchar(t_pf_env *e, char type)
{
	wchar_t *ws;
	wchar_t wc;

	e->flag.f & F_MINUS ? e->flag.f &= ~F_ZERO : 0;

	if (type == 's' || type == 'S')
	{
		init_wstr_arg(e, &ws);
		if (ws == NULL)
			return (print_null_str(e));
		print_wstr(e, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		init_wchar_arg(e, &wc);
		if (wc == 0)
			return (print_null_char(e));
		print_wchar(e, wc);
	}
}
