/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 18:38:55 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_hooking(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
