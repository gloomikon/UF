/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:34:23 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 18:36:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_exit(char *err)
{
	ft_printf("%s\n", err);
	system("leaks a.out");
	exit(1);
}

int		eclose(void *param)
{
	(void)param;
	exit(0);
}

void	init_fdf(t_fdf	*fdf)
{
	ft_bzero(&fdf->cam, sizeof(t_cam));
	fdf->cam.zdiv = 1;
	fdf->cam.zoom = ft_min(
		(WIDTH - MENU_WIDTH) / fdf->map.width / 2,
		HEIGHT / fdf->map.height / 2
	);
	fdf->beauty.line_color = 0xFF0000;
	fdf->beauty.ground_color = 0x000000;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf - KOLUMBIA");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->data = mlx_get_data_addr(fdf->img, &(fdf->bpp),
		&(fdf->sl), &(fdf->endian));
}

void	mlx_hooking(t_fdf *fdf)
{
	mlx_hook(fdf->win, 17, 0, eclose, fdf);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
}
