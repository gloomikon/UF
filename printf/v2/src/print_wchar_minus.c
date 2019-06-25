/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:03:27 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 15:03:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_wchar_minus(t_pf_env *e, wchar_t wc)
{
	put_wc(e, wc);
	while (e->flag.width-- > 1)
		e->ret += write(e->fd, " ", 1);
}
