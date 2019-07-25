/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 04:00:56 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_exit(char *err)
{
	ft_printf("%s\n", err);
	system("leaks a.out");
	exit(1);
}



void	init_fdf(t_fdf	*fdf)
{
	ft_bzero(&fdf->cam, sizeof(t_cam));
	fdf->cam.zdiv = 1;
	fdf->cam.zoom = ft_min(
		(WIDTH - MENU_WIDTH) / fdf->map.width / 2,
		HEIGHT / fdf->map.height / 2
	);
	fdf->color.line_color = 0xFF0000;
	fdf->color.ground_color = 0x000000;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf - KOLUMBIA");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data = mlx_get_data_addr(fdf->img, &(fdf->bpp),
		&(fdf->sl), &(fdf->endian));
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		*(int*)(fdf->data + (x + y * WIDTH) * fdf->bpp / 8) = color;
		// i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		// fdf->data[i++] = color;
		// fdf->data[i++] = color >> 8;
		// fdf->data[i] = color >> 16;
	}
}

void	bresenham(t_point3d from, t_point3d to, t_fdf *fdf)
{
	t_point3d	cur;
	t_point3d	delta;
	t_point3d	sign;
	int			err[2];

	delta.x = ft_abs(from.x - to.x);
	delta.y = ft_abs(from.y - to.y);
	sign.x = from.x < to.x ? 1 : -1;
	sign.y = from.y < to.y ? 1 : -1;
	err[0] = delta.x - delta.y;
	cur = from;
	while (cur.x != to.x || cur.y != to.y)
	{
		//put_pixel(fdf, cur.x, cur.y, get_color(cur, from, to, delta));
		put_pixel(fdf, cur.x, cur.y, cur.color);
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

void	draw_star(int x, int y, t_fdf *fdf)
{
	t_point3d from;
	t_point3d to;

	from.color = 0xFFFF00;
	to.color = 0xFFFF00;
	from.x = x;
	from.y = y;
	to.x = x - 15;
	to.y = y - 40;
	bresenham(from, to, fdf);
	to.x = x - 35;
	to.y = y - 25;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x + 40;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x - 35;
	to.y = from.y + 25;
	bresenham(from, to, fdf);
	from = to;
	to.x = from.x + 15;
	to.y = from.y - 40;
	bresenham(from, to, fdf);
}

void	draw_star_sky(t_fdf *fdf)
{
	draw_star(500, 500, fdf);
	draw_star(700, 900, fdf);
	draw_star(800, 100, fdf);
	draw_star(900, 100, fdf);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
	// draw_star(500, 500);
}

void	fill_bg(t_fdf *fdf)
{
	int	i;
	int	*img;

	ft_bzero(fdf->data, HEIGHT * WIDTH * (fdf->bpp / 8));
	img = (int*)(fdf->data);
	i = -1;
	while (++i < HEIGHT * WIDTH)
		img[i] = (i % WIDTH < MENU_WIDTH) ? MENUCOLOR : BGCOLOR;
	draw_star_sky(fdf);
}

 void	iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

static t_point3d	projection(int x, int y, int z, t_fdf *fdf)
{
	t_point3d	p;

	p.color = fdf->map.coords[y][x].color == -1 ?
		fdf->color.line_color : fdf->map.coords[y][x].color;
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

void	draw_fdf(t_fdf	*fdf)
{
	int x;
	int y;

	fill_bg(fdf);
	y = -1;
	while (++y < fdf->map.height && (x = -1))
		while(++x < fdf->map.width)
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
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		err_exit(ERR_USAGE);
	if ((fd = open(argv[1], O_RDONLY | O_DIRECTORY)) > 0)
		err_exit(ERR_FILE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		err_exit(ERR_FILE);
	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(fd, &fdf);
	close(fd);
	init_fdf(&fdf);
	draw_fdf(&fdf);
	mlx_loop(fdf.mlx);
	//print_data(&fdf);
	return (0);
}
