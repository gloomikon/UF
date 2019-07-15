/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:33:53 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:54:25 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_map(t_visualizer *v)
{
	v->map = newwin(MY + 2, (MX + 2) * 2, 18,
		v->map_size.x > 17 ? 5 : 7);
	wattron(v->map, COLOR_PAIR(14));
	box(v->map, 0, 0);
	wrefresh(v->map);
}
