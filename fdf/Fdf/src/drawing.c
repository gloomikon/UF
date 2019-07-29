/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:29:44 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 03:42:23 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_star(int x, int y, t_fdf *fdf)
{
	t_point3d from;
	t_point3d to;

	from.color = 0xFFFF00;
	to.color = 0xFFFF00;
	from.x = x;
	from.y = y;
	to.x = x - 3;
	to.y = y - 8;
	bresenham(from, to, fdf);
	to.x = x - 7;
	to.y = y - 5;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x + 8;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x - 7;
	to.y = from.y + 5;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x + 3;
	to.y = from.y - 8;
	bresenham(from, to, fdf);
}

void	draw_star_sky(t_fdf *fdf)
{
	draw_star(500, 500, fdf);
	draw_star(700, 900, fdf);
	draw_star(800, 100, fdf);
	draw_star(900, 200, fdf);
	draw_star(2000, 300, fdf);
	draw_star(1800, 700, fdf);
	draw_star(900, 900, fdf);
	draw_star(710, 382, fdf);
	draw_star(506, 1176, fdf);
	draw_star(863, 491, fdf);
	draw_star(2547, 1162, fdf);
	draw_star(1555, 966, fdf);
	draw_star(2496, 492, fdf);
	draw_star(2529, 1298, fdf);
	draw_star(1919, 614, fdf);
	draw_star(1643, 234, fdf);
	draw_star(2063, 928, fdf);
	draw_star(1682, 480, fdf);
	draw_star(2250, 300, fdf);
	draw_star(2087, 1225, fdf);
	draw_star(1979, 1276, fdf);
	draw_star(422, 1155, fdf);
	draw_star(595, 1168, fdf);
	draw_star(1619, 588, fdf);
	draw_star(1448, 1168, fdf);
}

void	fill_bg(t_fdf *fdf)
{
	int	i;
	int	*img;

	ft_bzero(fdf->data, HEIGHT * WIDTH * (fdf->bpp / 8));
	img = (int*)(fdf->data);
	i = -1;
	while (++i < HEIGHT * WIDTH)
		img[i] = (i % WIDTH < fdf->beauty.menu * MENU_WIDTH) ?
			MENUCOLOR : BGCOLOR;
	draw_star_sky(fdf);
}

void	draw_fdf(t_fdf *fdf)
{
	int x;
	int y;

	fill_bg(fdf);
	y = -1;
	while (++y < fdf->map.height && (x = -1))
		while (++x < fdf->map.width)
		{
			if (x != fdf->map.width - 1)
				bresenham(
					projection(x, y, fdf->map.coords[y][x].z, fdf),
					projection(x + 1, y, fdf->map.coords[y][x + 1].z, fdf),
					fdf);
			if (y != fdf->map.height - 1)
				bresenham(
					projection(x, y, fdf->map.coords[y][x].z, fdf),
					projection(x, y + 1, fdf->map.coords[y + 1][x].z, fdf),
					fdf);
		}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
