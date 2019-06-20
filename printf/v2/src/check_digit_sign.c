/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:12:22 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/20 11:16:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_digit_sign(t_pf_env *e)
{
	char *tmp;

	if (e->out[0] == '-')
	{
		tmp = ft_strdup(e->out + 1);
		ft_strdel(&e->out);
		e->out = tmp;
		e->flag.f &= ~(F_SPACE | F_PLUS);
		e->flag.f |= F_NEGATIVE;
	}
}
