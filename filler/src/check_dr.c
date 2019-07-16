/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:46:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 18:46:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_dr(t_filler *filler)
{
	if (right_side(filler) && ft_strchr(MI[MH - 1], ME))
		filler->direction = F_RIGHT;
	else if (filler->diff.y > filler->diff.x)
		filler->direction = ft_strchr(MI[MH - 1], ME) ?
		RIGHT : DOWN;
	else
		filler->direction = right_side(filler) ? DOWN : RIGHT;
}
