/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:49:11 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 18:26:43 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit_sign(t_pf_env *e)
{
	if (e->flag.f & F_PLUS)
		e->ret += write(e->fd, "+", 1);
	else if (e->flag.f & F_SPACE)
		e->ret += write(e->fd, " ", 1);
	else if (e->flag.f & F_NEGATIVE)
		e->ret += write(e->fd, "-", 1);
}

