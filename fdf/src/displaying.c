/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:37:12 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 02:20:12 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int*)(fdf->data + (x + y * WIDTH) * fdf->bpp / 8) = color;
}

void	bresenham(t_point3d from, t_point3d to, t_fdf *fdf)
{
	int			err[2];
	t_point3d	cur;
	t_point3d	delta;
	t_point3d	sign;

	delta.x = ft_abs(from.x - to.x);
	delta.y = ft_abs(from.y - to.y);
	sign.x = from.x < to.x ? 1 : -1;
	sign.y = from.y < to.y ? 1 : -1;
	err[0] = delta.x - delta.y;
	cur = from;
	while (cur.x != to.x || cur.y != to.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, from, to, delta));
		if ((err[1] = err[0] * 2) > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += sign.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
