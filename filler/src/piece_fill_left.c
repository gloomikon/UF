/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_fill_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:29:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:27:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_fill_left(t_filler *filler)
{
	t_point loop;

	loop.x = -1;
	while (++loop.x < MW && (loop.y = -1))
		while (++loop.y < MH)
			if (check_valid(filler, loop.y, loop.x))
				return (cr_point(loop.x, loop.y));
	return (cr_point(0, 0));
}
