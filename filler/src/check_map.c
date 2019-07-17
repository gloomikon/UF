/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:43:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 18:07:57 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_map(t_filler *filler)
{
	filler->diff = (filler->corner == DOWN_RIGHT) ?
	cr_point(get_left(filler->map, ME) -
			get_right(filler->map, filler->bot),
			get_top(filler->map, ME) -
			get_bottom(filler->map, filler->bot)) :
	cr_point(get_left(filler->map, filler->bot) -
			get_right(filler->map, ME),
			get_top(filler->map, filler->bot) -
			get_bottom(filler->map, ME));
	filler->corner == DOWN_RIGHT ? check_ul(filler) : check_dr(filler);
}
