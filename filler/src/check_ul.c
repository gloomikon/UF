/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:44:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:45:42 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_ul(t_filler *filler)
{
	if (left_side(filler) && ft_strchr(MI[0], filler->me))
		init_filler(FILL, cr_point(0, 0), cr_point(MW, MH), filler);
	else if (filler->diff.y > filler->diff.x)
		ft_strchr(MI[0], filler->me) ?
		init_filler(PUT, cr_point(-PW + 1, MH - 1), cr_point(MW, 0), filler) :
		init_filler(PUT, cr_point(-PW + 1, -PH + 1), cr_point(MW, MH), filler);
	else
		(left_side(filler)) ?
		init_filler(PUT, cr_point(-PW + 1, -PH + 1), cr_point(MW, MH), filler) :
		init_filler(PUT, cr_point(-PW + 1, MH - 1), cr_point(MW, 0), filler);
}
