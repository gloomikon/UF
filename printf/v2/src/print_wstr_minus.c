/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:35:10 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 14:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_wstr_minus(t_pf_env *e, wchar_t *wc, int len)
{
	int i;

	i = -1;
	if (e->flag.prec >= 0)
	{
		while (wc[++i] != 0 && i < e->flag.prec)
			put_wstr(e, wc[i]);
	}
	else
	{
		while (wc[++i] != 0)
			put_wstr(e, wc[i]);
	}
	while (e->flag.width-- > len)
		e->ret += (e->flag.f & F_ZERO ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}
