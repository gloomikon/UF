/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:39:18 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:39:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_bottom(t_object map, char who)
{
	t_point loop;

	loop.y = map.height;
	while (--loop.y >= 0 && (loop.x = -1))
		while (++loop.x < map.width)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.y);
	return (0);
}
