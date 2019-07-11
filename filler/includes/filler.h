/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:01:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:52:43 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf/includes/header.h"

# define EQUALS(a, b)	(a == b) || (a == b + 32)

# define UP_LEFT	7
# define DOWN_RIGHT 3

# define MW			filler->map.width
# define MH			filler->map.height
# define MI			filler->map.info
# define PW			filler->piece.width
# define PH			filler->piece.height
# define PI			filler->piece.info

# define PUT		0
# define FILL		1

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_object
{
	int			height;
	int			width;
	int			size;
	char		**info;
}				t_object;

typedef struct	s_filler
{
	char		me;
	char		bot;
	t_object	map;
	t_object	piece;
	t_point		diff;
	int			corner;
	int			put_or_fill;
	t_point		from;
	t_point		to;
	t_point		result;
}				t_filler;

void			get_player(t_filler *filler);
void			read_data(t_filler *filler);
void			read_piece(char *line, t_object *piece);
void			read_map(char *line, t_object *map);
int				init_corner(t_filler *filler);

int				get_bottom(t_object map, char who);
int				get_top(t_object map, char who);
int				get_left(t_object map, char who);
int				get_right(t_object map, char who);

void			fit_piece(t_filler *filler);
void			check_map(t_filler *filler);
void			check_ul(t_filler *filler);
void			check_dr(t_filler *filler);
int				left_side(t_filler *filler);
int				right_side(t_filler *filler);
t_point			fill(t_filler *filler);
t_point			put(t_filler *filler);
int				check_valid(t_filler *filler, int y, int x);

int				invalid_pos(int y, int x, t_object map);
t_point			cr_point(int x, int y);
void			init_filler(int put_or_fill, t_point from,
				t_point to, t_filler *filler);

#endif
