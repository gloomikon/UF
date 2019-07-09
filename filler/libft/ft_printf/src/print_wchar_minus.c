/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:15:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_wchar_minus(t_pf_env *e, wchar_t wc)
{
	put_wc(e, wc);
	while (e->flag.width-- > 1)
		e->ret += write(e->fd, " ", 1);
}
