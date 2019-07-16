/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:35:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 18:08:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	init_corner(t_filler *filler)
{
	t_point loop;

	loop.y = -1;
	while (++loop.y < MH && (loop.x = -1))
		while (++loop.x < MW)
			if (MI[loop.y][loop.x] == ME)
				return (UP_LEFT);
			else if (MI[loop.y][loop.x] == filler->bot)
				return (DOWN_RIGHT);
	return (0);
}
