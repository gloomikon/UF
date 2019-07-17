/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_put_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:30:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 23:00:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_put_right(t_filler *filler)
{
	t_point loop;

	loop.y = -PH;
	while (++loop.y < MH && (loop.x = MW))
		while (--loop.x >= -PW)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(-PW - 1, -PH - 1));
}
