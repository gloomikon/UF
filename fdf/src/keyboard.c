/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:23:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 19:48:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(int key, t_fdf *fdf)
{
	key == RIGHT_2 ? fdf->cam.alpha += 0.05 : 0;
	key == RIGHT_8 ? fdf->cam.alpha -= 0.05 : 0;
	key == RIGHT_4 ? fdf->cam.beta += 0.05 : 0;
	key == RIGHT_6 ? fdf->cam.beta -= 0.05 : 0;
	(key == RIGHT_1 || key == RIGHT_3) ? fdf->cam.gamma += 0.05 : 0;
	(key == RIGHT_7 || key == RIGHT_9) ? fdf->cam.gamma -= 0.05 : 0;
	ft_printf("", key);
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
	return (0);
}