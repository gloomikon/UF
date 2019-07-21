/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_fill_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:29:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 22:59:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_fill_left(t_filler *filler)
{
	t_point loop;

	loop.x = -PW;
	while (++loop.x < MW && (loop.y = -PH))
		while (++loop.y < MH)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(-PW - 1, -PH - 1));
}
