/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_put_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:30:32 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:27:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_put_left(t_filler *filler)
{
	t_point loop;

	loop.y = MH;
	while (--loop.y >= 0 && (loop.x = -PW))
		while (++loop.x < MW)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(0, 0));
}
