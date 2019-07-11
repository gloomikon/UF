/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:43:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:43:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_map(t_filler *filler)
{
	filler->diff = (filler->corner == DOWN_RIGHT) ?
	cr_point(get_left(filler->map, filler->me) -
				get_right(filler->map, filler->bot),
					get_top(filler->map, filler->me) -
					get_bottom(filler->map, filler->bot)) :
	cr_point(get_left(filler->map, filler->bot) -
				get_right(filler->map, filler->me),
					get_top(filler->map, filler->bot) -
					get_bottom(filler->map, filler->me));
	filler->corner == DOWN_RIGHT ? check_ul(filler) : check_dr(filler);
}
