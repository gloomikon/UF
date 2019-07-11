/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:48:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:49:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	put(t_filler *filler)
{
	t_point loop;

	loop = filler->from;
	while (loop.y != filler->to.y)
	{
		loop.x = filler->from.x;
		while (loop.x != filler->to.x)
		{
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
			loop.x += (loop.y < filler->to.x) ? 1 : -1;
		}
		loop.y += (loop.y < filler->to.y) ? 1 : -1;
	}
	return (cr_point(-1, -1));
}
