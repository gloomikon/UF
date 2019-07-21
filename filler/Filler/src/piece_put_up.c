/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_put_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:32:29 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 23:00:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_put_up(t_filler *filler)
{
	t_point loop;

	loop.y = -PH;
	while (++loop.y < MH && (loop.x = -PW))
		while (++loop.x < MW)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(-PW - 1, -PH - 1));
}
