/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:41:32 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:42:04 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_right(t_object map, char who)
{
	t_point loop;

	loop.x = map.width;
	while (--loop.x >= 0 && (loop.y = -1))
		while (++loop.y < map.height)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.x);
	return (-1);
}
