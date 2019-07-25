/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:44:42 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/26 02:24:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fullfill_data(t_point_lst **lst, t_fdf *fdf)
{
	int			i;
	int			j;
	t_point_lst	*point;

	fdf->map.zmin = INT_MAX;
	fdf->map.zmax = INT_MIN;
	fdf->map.coords = (t_point**)malloc(sizeof(t_point*) * fdf->map.height);
	i = -1;
	while (++i < fdf->map.height)
		fdf->map.coords[i] =
			(t_point*)malloc(sizeof(t_point) * fdf->map.width);
	while (--i >= 0 && (j = fdf->map.width))
		while (--j >= 0 && (point = lst_pop(lst)))
		{
			fdf->map.coords[i][j] = point->val;
			fdf->map.zmin > point->val.z ? fdf->map.zmin = point->val.z : 0;
			fdf->map.zmax < point->val.z ? fdf->map.zmax = point->val.z : 0;
			free(point);
		}
	fdf->map.zdelta = fdf->map.zmax - fdf->map.zmin;
}

void	read_map(int fd, t_fdf *fdf)
{
	char		*line;
	char		**split;
	int			res;
	int			width;
	t_point_lst	*lst;

	lst = NULL;
	while (get_next_line(fd, &line) && !(width = 0) && (++fdf->map.height))
	{
		split = ft_strsplit(line, ' ');
		ft_strdel(&line);
		while (split[width])
			lst_push(&lst, new_point(split[width++], fdf));
		free_split_array(split);
		fdf->map.width = fdf->map.height == 1 ? width : fdf->map.width;
		if (fdf->map.width != width)
		{
			free_lst(&lst);
			err_exit(ERR_MAP);
		}
	}
	if (fdf->map.height == 0)
		err_exit(ERR_MAP);
	fullfill_data(&lst, fdf);
}
