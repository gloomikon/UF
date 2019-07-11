/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:46:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:46:24 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_dr(t_filler *filler)
{
	if (right_side(filler) && ft_strchr(MI[MH - 1], filler->me))
		init_filler(FILL, cr_point(MW - 1, MH - 1), cr_point(0, 0), filler);
	else if (filler->diff.y > filler->diff.x)
		ft_strchr(MI[MH - 1], filler->me) ?
		init_filler(PUT, cr_point(MW - 1, 0), cr_point(0, MH), filler) :
		init_filler(PUT, cr_point(MW - 1, MH - 1), cr_point(0, 0), filler);
	else
		(right_side(filler)) ?
		init_filler(PUT, cr_point(MW - 1, MH - 1), cr_point(0, 0), filler) :
		init_filler(PUT, cr_point(MW - 1, 0), cr_point(0, MH), filler);
}
