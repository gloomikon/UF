/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/22 21:34:47 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "header.h"
# include <fcntl.h>

# define ERR_USAGE			"Usage: ./fdf <filename>"
# define ERR_FILE			"Incorrect filename"
# define ERR_MAP			"Incorrect map"

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
	int					zrange;	//?
}						t_map;

typedef struct			s_fdf
{
	t_map				map;
}						t_fdf;

#endif