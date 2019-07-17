/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:40:41 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:40:47 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_left(t_object map, char who)
{
	t_point loop;

	loop.x = -1;
	while (++loop.x < map.width && (loop.y = -1))
		while (++loop.y < map.height)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.x);
	return (map.width + 1);
}
