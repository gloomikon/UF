/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 03:40:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 03:52:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*create_color_value(char *color, int value)
{
	char	*res;
	char	*tmp;

	tmp = ft_itoa(value);
	res = ft_strjoin(color, tmp);
	ft_strdel(&tmp);
	return (res);
}

void	print_menu_color_values(t_fdf *fdf)
{
	void	*mlx;
	void	*win;
	char	*s;

	mlx = fdf->mlx;
	win = fdf->win;
	s = create_color_value("red     ", (fdf->beauty.line_color >> 16) & 0xFF);
	mlx_string_put(mlx, win, 200, 560, 0xFFFFFF, s);
	ft_strdel(&s);
	s = create_color_value("green   ", (fdf->beauty.line_color >> 8) & 0xFF);
	mlx_string_put(mlx, win, 200, 590, 0xFFFFFF, s);
	ft_strdel(&s);
	s = create_color_value("blue    ", (fdf->beauty.line_color) & 0xFF);
	mlx_string_put(mlx, win, 200, 620, 0xFFFFFF, s);
	ft_strdel(&s);
	s = create_color_value("red     ", (fdf->beauty.ground_color >> 16) & 0xFF);
	mlx_string_put(mlx, win, 200, 680, 0xFFFFFF, s);
	ft_strdel(&s);
	s = create_color_value("green   ", (fdf->beauty.ground_color >> 8) & 0xFF);
	mlx_string_put(mlx, win, 200, 710, 0xFFFFFF, s);
	ft_strdel(&s);
	s = create_color_value("blue    ", (fdf->beauty.ground_color) & 0xFF);
	mlx_string_put(mlx, win, 200, 740, 0xFFFFFF, s);
	ft_strdel(&s);
}

void	print_menu_colors(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	if (!fdf->beauty.has_color)
	{
		mlx = fdf->mlx;
		win = fdf->win;
		mlx_string_put(mlx, win, 50, 380, 0xFFFFFF, "Change line color RGB:");
		mlx_string_put(mlx, win, 200, 410, 0xFFFFFF, "Q/S W/S E/D");
		mlx_string_put(mlx, win, 50, 440, 0xFFFFFF, "Change ground color RGB:");
		mlx_string_put(mlx, win, 200, 470, 0xFFFFFF, "T/G Y/H U/J");
		mlx_string_put(mlx, win, 0, 490, 0xFFFFFF, "__________________________"
							"______________");
		mlx_string_put(mlx, win, 50, 530, 0xFFFFFF, "Line colors values:");
		mlx_string_put(mlx, win, 50, 650, 0xFFFFFF, "Ground colors values:");
		print_menu_color_values(fdf);
	}
}

void	print_menu(t_fdf *fdf)
{
	void	*mlx;
	void	*win;

	if (fdf->beauty.menu)
	{
		mlx = fdf->mlx;
		win = fdf->win;
		mlx_string_put(mlx, win, 150, 20, 0xFFFFFF, "INSTRUCTION");
		mlx_string_put(mlx, win, 0, 40, 0xFFFFFF, "__________________________"
							"______________");
		mlx_string_put(mlx, win, 50, 80, 0xFFFFFF, "Move: Arrows");
		mlx_string_put(mlx, win, 50, 110, 0xFFFFFF, "Rotate X: NumPad 2/8");
		mlx_string_put(mlx, win, 50, 140, 0xFFFFFF, "Rotate Y: NumPad 4/6");
		mlx_string_put(mlx, win, 50, 170, 0xFFFFFF, "Rotate Z: NumPad 1/3/7/9");
		mlx_string_put(mlx, win, 50, 200, 0xFFFFFF, "Zoom: NumPad +/-");
		mlx_string_put(mlx, win, 50, 230, 0xFFFFFF,
										"Change height: PageUp/PageDown");
		mlx_string_put(mlx, win, 50, 260, 0xFFFFFF, "Change projection: I/P");
		mlx_string_put(mlx, win, 50, 290, 0xFFFFFF, "Hide menu: ENTER");
		mlx_string_put(mlx, win, 50, 320, 0xFFFFFF, "Hide ground: SPACE");
		mlx_string_put(mlx, win, 50, 350, 0xFFFFFF, "Exit: ESCAPE");
		print_menu_colors(fdf);
		mlx_string_put(mlx, win, 150, 1270, 0xFFFFFF, "by KolumbiA");
	}
}
