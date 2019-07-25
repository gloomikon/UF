/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 18:39:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "header.h"
# include "key_codes.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <math.h>


# define HEIGHT		1315
# define WIDTH		2560
# define MENU_WIDTH	400

# define BGCOLOR	0x000000
# define MENUCOLOR	0x660066


# define ERR_USAGE	"Usage: ./fdf <filename>"
# define ERR_FILE	"Incorrect filename"
# define ERR_MAP	"Incorrect map"

# define ISO		0
# define PARALLEL	1

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

typedef	struct			s_beauty
{
	int					has_color;
	int					ground_color;
	int					line_color;
}						t_beauty;

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
	t_beauty			beauty;
}						t_fdf;

void	err_exit(char *err);

/*
** WORK WITH LIST
*/

void		lst_push(t_point_lst **lst, t_point_lst *new);
t_point_lst	*lst_pop(t_point_lst **lst);
t_point_lst	*new_point(char *s, t_fdf *fdf);

/*
** FREE MEMORY
*/

void	free_split_array(char **split);
void	free_lst(t_point_lst **lst);

/*
** READ MAP
*/

void	read_map(int fd, t_fdf *fdf);

/*
** DRAWING & DISPLAYING
*/

void	draw_star(int x, int y, t_fdf *fdf);
void	draw_star_sky(t_fdf *fdf);
void	fill_bg(t_fdf *fdf);
void	draw_fdf(t_fdf	*fdf);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	bresenham(t_point3d from, t_point3d to, t_fdf *fdf);

/*
** TRANSFORMATION
*/

void	iso(int *x, int *y, int z);
t_point3d	projection(int x, int y, int z, t_fdf *fdf);

/*
** AUXILIARY FUNCTIONS
*/

void	err_exit(char *err);
int		eclose(void *param);
void	init_fdf(t_fdf	*fdf);
void	mlx_hooking(t_fdf *fdf);


#endif