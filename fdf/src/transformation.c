/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:38:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 19:57:38 by mzhurba          ###   ########.fr       */
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

void	transform_x_axis(int *y, int *z, double alpha)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	transform_y_axis(int *x, int *z, double beta)
{
	int prev;

	prev = *x;
	*x = prev * cos(beta) + *z * sin(beta);
	*z = -prev * sin(beta) + *z * cos(beta);
}

void	transform_z_axis(int *x, int *y, double gamma)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

t_point3d	projection(int x, int y, int z, t_fdf *fdf)
{
	t_point3d	p;

	//part with color
	p.color = fdf->map.coords[y][x].color == -1 ?
		fdf->beauty.line_color : fdf->map.coords[y][x].color;
	//rewrite !!!
	x = x * fdf->cam.zoom - (fdf->map.width * fdf->cam.zoom) / 2;
	y = y * fdf->cam.zoom - (fdf->map.height * fdf->cam.zoom) / 2;
	z *= fdf->cam.zoom / fdf->cam.zdiv / 5;
	transform_x_axis(&y, &z, fdf->cam.alpha);
	transform_y_axis(&x, &z, fdf->cam.beta);
	transform_z_axis(&x, &y, fdf->cam.gamma);
	if (fdf->cam.projection == ISO)
		iso(&x, &y, z);
	x += (WIDTH - MENU_WIDTH) / 2 + fdf->cam.xoffset + MENU_WIDTH;
	y += (HEIGHT + fdf->map.height * fdf->cam.zoom) / 2
												+ fdf->cam.yoffset;
	p.x = x;
	p.y = y;
	return (p);
}
