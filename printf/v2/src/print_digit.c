/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:05:28 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 18:24:01 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit(t_pf_env *e)
{
	check_digit_prec(e);
	if (e->flag.f & F_ZERO)
	{
		print_digit_sign(e);
		print_digit_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
}
