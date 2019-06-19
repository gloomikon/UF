/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:12:22 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 17:17:56 by mzhurba          ###   ########.fr       */
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
		e->flag.f &= ~(F_SPACE | F_PLUS);
		e->flag.f |= F_NEGATIVE;
	}
}
