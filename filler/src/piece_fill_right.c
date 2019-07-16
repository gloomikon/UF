/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_fill_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:28:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:27:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_fill_right(t_filler *filler)
{
	t_point loop;

	loop.x = MW;
	while (--loop.x >= 0 && (loop.y = MH))
		while (--loop.y >= 0)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(0, 0));
}
