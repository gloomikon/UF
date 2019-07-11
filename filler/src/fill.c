/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:48:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:48:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	fill(t_filler *filler)
{
	t_point loop;

	loop = filler->from;
	while (loop.x != filler->to.x)
	{
		loop.y = filler->from.y;
		while (loop.y != filler->to.y)
		{
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
			loop.y += (loop.y < filler->to.y) ? 1 : -1;
		}
		loop.x += (loop.x < filler->to.x) ? 1 : -1;
	}
	return (cr_point(-1, -1));
}
