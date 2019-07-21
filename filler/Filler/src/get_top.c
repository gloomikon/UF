/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:38:47 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:38:54 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_top(t_object map, char who)
{
	t_point loop;

	loop.y = -1;
	while (++loop.y < map.height && (loop.x = -1))
		while (++loop.x < map.width)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.y);
	return (0);
}
