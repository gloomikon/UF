/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 03:37:19 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

# define BGCOLOR		0x000000
# define MENUCOLOR		0x660066

# include "header.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <math.h>

# define ERR_USAGE			"Usage: ./fdf <filename>"
# define ERR_FILE			"Incorrect filename"
# define ERR_MAP			"Incorrect map"

# define ISO	0

typedef struct			s_point3d
{
	int					x;
	int					y;
	int					z;
	int					color;
} 						t_point3d;

typedef struct			s_point
{
	int					z;
	int					color;
}						t_point;

typedef struct			s_point_lst
{
	t_point				val;
	struct s_point_lst	*nxt;
}						t_point_lst;

typedef struct			s_map
{
	t_point				**coords;
	int					width;
	int					height;
	int					zmin;
	int					zmax;
	int					zdelta;
}						t_map;

typedef struct			s_cam
{
	int					projection;
	int					zoom;
	int					alpha;
	int					beta;
	int					gamma;
	double				zdiv;
	int					xoffset;
	int					yoffset;
}						t_cam;

typedef	struct			s_color
{
	int					has_color;
	int					ground_color;
	int					line_color;
}						t_color;

typedef struct			s_fdf
{
	t_map				map;
	t_cam				cam;
	void				*mlx;
	void				*img;
	void				*win;
	char				*data;
	int					bpp;
	int					sl;
	int					endian;
	t_color				color;
}						t_fdf;

void	err_exit(char *err);
/*
** WORK WITH LIST
*/

void		lst_push(t_point_lst **lst, t_point_lst *new);
t_point_lst	*lst_pop(t_point_lst **lst);
t_point_lst	*new_point(char *s, t_fdf *fdf);


void	free_split_array(char **split);
void	free_lst(t_point_lst **lst);
void	read_map(int fd, t_fdf *fdf);

#endif