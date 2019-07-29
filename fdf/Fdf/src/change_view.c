/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:23:02 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 02:39:27 by mzhurba          ###   ########.fr       */
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
}

void	change_pos(int key, t_fdf *fdf)
{
	key == LEFT ? fdf->cam.xoffset -= 10 : 0;
	key == RIGHT ? fdf->cam.xoffset += 10 : 0;
	key == UP ? fdf->cam.yoffset -= 10 : 0;
	key == DOWN ? fdf->cam.yoffset += 10 : 0;
}

void	change_zoom(int key, t_fdf *fdf)
{
	key == RIGHT_PLUS ? fdf->cam.zoom++ : fdf->cam.zoom--;
	!fdf->cam.zoom ? fdf->cam.zoom = 1 : 0;
}

void	change_height(int key, t_fdf *fdf)
{
	fdf->cam.zdiv += (key == Z_UP) ? 2 : -2;
	fdf->cam.zdiv > 100 ? fdf->cam.zdiv = 100 : 0;
	fdf->cam.zdiv < -100 ? fdf->cam.zdiv = -100 : 0;
}

void	change_proj(int key, t_fdf *fdf)
{
	fdf->cam.alpha = 0;
	fdf->cam.beta = 0;
	fdf->cam.gamma = 0;
	fdf->cam.projection = (key == LETTER_I) ? ISO : PARALLEL;
}
