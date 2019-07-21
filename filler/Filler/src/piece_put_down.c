/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_put_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:29:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 23:00:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_put_down(t_filler *filler)
{
	t_point loop;

	loop.y = MH;
	while (--loop.y >= -PH && (loop.x = MW))
		while (--loop.x >= -PW)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(-PW - 1, -PH - 1));
}
