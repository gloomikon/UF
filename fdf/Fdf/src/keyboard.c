/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:23:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 04:16:44 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	(key == ESC) ? exit(0) : 0;
	(key >= RIGHT_1 && key <= RIGHT_9) ? change_angle(key, fdf) : 0;
	(key >= LEFT && key <= UP) ? change_pos(key, fdf) : 0;
	(key == RIGHT_PLUS || key == RIGHT_MINUS) ? change_zoom(key, fdf) : 0;
	(key == Z_UP || key == Z_DOWN) ? change_height(key, fdf) : 0;
	(key == LETTER_P || key == LETTER_I) ? change_proj(key, fdf) : 0;
	(key == SPACE) ? fdf->beauty.ground = !fdf->beauty.ground : 0;
	(key == ENTER) ? fdf->beauty.menu = !fdf->beauty.menu : 0;
	(LETTER_LINE(key) || LETTER_GROUND(key)) ? change_color(key, fdf) : 0;
	draw_fdf(fdf);
	return (0);
}
