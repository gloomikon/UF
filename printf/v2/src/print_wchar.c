/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:02:24 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 15:02:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.f & F_MINUS)
		print_wchar_minus(e, wc);
	else
	{
		while (e->flag.width-- > 1)
			e->ret += (e->flag.f & F_ZERO ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		put_wc(e, wc);
	}
	++e->i;
}
