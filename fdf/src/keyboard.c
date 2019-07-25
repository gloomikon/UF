/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:23:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 21:03:44 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(int key, t_fdf *fdf)
{
	key == RIGHT_2 ? fdf->cam.alpha += 0.05 : 0;
	key == RIGHT_8 ? fdf->cam.alpha -= 0.05 : 0;
	key == RIGHT_4 ? fdf->cam.beta += 0.05 : 0;
	key == RIGHT_6 ? fdf->cam.beta -= 0.05 : 0;
	(key == RIGHT_1 || key == RIGHT_7) ? fdf->cam.gamma += 0.05 : 0;
	(key == RIGHT_3 || key == RIGHT_9) ? fdf->cam.gamma -= 0.05 : 0;
	draw_fdf(fdf);
}

void	change_pos(int key, t_fdf *fdf)
{
	key == LEFT ? fdf->cam.xoffset -= 10 : 0;
	key == RIGHT ? fdf->cam.xoffset += 10 : 0;
	key == UP ? fdf->cam.yoffset -= 10 : 0;
	key == DOWN ? fdf->cam.yoffset += 10 : 0;
	draw_fdf(fdf);
}

void	change_zoom(int key, t_fdf *fdf)
{
	key == RIGHT_PLUS ? fdf->cam.zoom++ : fdf->cam.zoom--;
	!fdf->cam.zoom ? fdf->cam.zoom = 1 : 0; 
	draw_fdf(fdf);
}

void	change_height(int key, t_fdf *fdf)
{
	fdf->cam.zdiv += key == Z_UP ? 0.1 : -0.1;
	fdf->cam.zdiv > 10 ? fdf->cam.zdiv = 10 : 0;
	draw_fdf(fdf);
}

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == ESC)
	{
		system("leaks -q a.out");
		exit(0);
	}
	(key >= RIGHT_1 && key <= RIGHT_9) ? change_angle(key, fdf) : 0;
	(key >= LEFT && key <= UP) ? change_pos(key, fdf) : 0;
	(key == RIGHT_PLUS || key == RIGHT_MINUS) ? change_zoom(key, fdf) : 0;
	(key == Z_UP || key == Z_DOWN) ? change_height(key, fdf) : 0;
	return (0);
}