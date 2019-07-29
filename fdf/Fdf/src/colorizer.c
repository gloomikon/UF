/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:19:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 02:23:41 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_light(int start, int end, double p)
{
	return ((int)((1 - p) * start + p * end));
}

int		get_color(t_point3d current, t_point3d start,
						t_point3d end, t_point3d delta)
{
	int		red;
	int		green;
	int		blue;
	double	p;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		p = percent(start.x, end.x, current.x);
	else
		p = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF, p);
	green = get_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF, p);
	blue = get_light(start.color & 0xFF,
					end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}

int		gradient(int z, t_fdf *fdf, int type)
{
	double		p;
	t_point3d	color;

	if ((p = percent(fdf->map.zmin, fdf->map.zmax, z)) >= 0 && type == 1)
	{
		if (p < 0.14)
			return (0xFF0000);
		if (p < 0.28)
			return (0xFF6600);
		if (p < 0.43)
			return (0xFFFF00);
		if (p < 0.57)
			return (0x33CC33);
		if (p < 0.72)
			return (0x66CCFF);
		return (p < 0.86) ? (0x0000FF) : (0x6600CC);
	}
	color.x = get_light((fdf->beauty.ground_color >> 16) & 0xFF,
					(fdf->beauty.line_color >> 16) & 0xFF, p);
	color.y = get_light((fdf->beauty.ground_color >> 8) & 0xFF,
					(fdf->beauty.line_color >> 8) & 0xFF, p);
	color.z = get_light(fdf->beauty.ground_color & 0xFF,
					fdf->beauty.line_color & 0xFF, p);
	return ((color.x << 16) | (color.y << 8) | color.z);
}

int		generate_color(int x, int y, int z, t_fdf *fdf)
{
	int color;

	if (fdf->beauty.has_color)
		color = (fdf->map.coords[y][x].color == -1) ?
			gradient(z, fdf, 1) : fdf->map.coords[y][x].color;
	else
		color = gradient(z, fdf, 2);
	if (!fdf->beauty.ground && z == 0)
		color = 0x000000;
	return (color);
}

void	change_color(int key, t_fdf *fdf)
{
	t_point3d	p;

	p.x = ((LETTER_LINE(key) ?
		fdf->beauty.line_color : fdf->beauty.ground_color) >> 16) & 0xFF;
	p.y = ((LETTER_LINE(key) ?
		fdf->beauty.line_color : fdf->beauty.ground_color) >> 8) & 0xFF;
	p.z = (LETTER_LINE(key) ?
		fdf->beauty.line_color : fdf->beauty.ground_color) & 0xFF;
	(key == LETTER_Q || key == LETTER_T) ? p.x += 5 : 0;
	(key == LETTER_W || key == LETTER_Y) ? p.y += 5 : 0;
	(key == LETTER_E || key == LETTER_U) ? p.z += 5 : 0;
	(key == LETTER_A || key == LETTER_G) ? p.x -= 5 : 0;
	(key == LETTER_S || key == LETTER_H) ? p.y -= 5 : 0;
	(key == LETTER_D || key == LETTER_J) ? p.z -= 5 : 0;
	if (p.x > 255 || p.x < 0)
		p.x = p.x > 255 ? 255 : 0;
	if (p.y > 255 || p.y < 0)
		p.y = p.y > 255 ? 255 : 0;
	if (p.z > 255 || p.z < 0)
		p.z = p.z > 255 ? 255 : 0;
	if (LETTER_LINE(key))
		fdf->beauty.line_color = ((p.x << 16) | (p.y << 8) | p.z);
	else
		fdf->beauty.ground_color = ((p.x << 16) | (p.y << 8) | p.z);
}
