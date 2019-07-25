/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:38:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 18:39:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

t_point3d	projection(int x, int y, int z, t_fdf *fdf)
{
	t_point3d	p;

	p.color = fdf->map.coords[y][x].color == -1 ?
		fdf->beauty.line_color : fdf->map.coords[y][x].color;
	x = x * fdf->cam.zoom - (fdf->map.width * fdf->cam.zoom) / 2;
	y = y * fdf->cam.zoom - (fdf->map.height * fdf->cam.zoom) / 2;
	z *= fdf->cam.zoom / fdf->cam.zdiv / 5;
	// rotate_x(&y, &z, fdf->cam.alpha);
	// rotate_y(&x, &z, fdf->cam.beta);
	// rotate_z(&x, &y, fdf->cam.gamma);
	if (fdf->cam.projection == ISO)
		iso(&x, &y, z);
	x += (WIDTH - MENU_WIDTH) / 2 + fdf->cam.xoffset + MENU_WIDTH;
	y += (HEIGHT + fdf->map.height * fdf->cam.zoom) / 2
												+ fdf->cam.yoffset;
	p.x = x;
	p.y = y;
	return (p);
}
