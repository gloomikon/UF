/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 03:35:48 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:53:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "header.h"
# include <curses.h>
# include <locale.h>

# define BOT	"\xF0\x9F\x8D\x93"
# define ME		"\xF0\x9F\x8D\x8C"
# define DELAY	10000
# define COLOR_ORANGE	172

# define MX v->map_size.x
# define MY v->map_size.y

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_visualizer
{
	WINDOW		*map;
	WINDOW		*score;
	WINDOW		*header;
	int			size;
	t_point		map_size;
	t_point		scores;
	char		*p1;
	char		*p2;
}				t_visualizer;

void			init_players(t_visualizer *v);
void			init_header(t_visualizer *v);
void			init_score_meter(t_visualizer *v);
void			init_map(t_visualizer *v);
void			read_size(char *line, t_visualizer *v);
void			colorizer();
void			init_screen(char *line, t_visualizer *v);
void			print_one_line(char *line, int i, t_visualizer *v);
void			update_map(t_visualizer *v);
char			*create_score_line(int player, t_visualizer *v);
void			update_score_meter(t_visualizer *v);
void			update(t_visualizer *v);
void			init_winner(t_visualizer *v);
void			end_free(t_visualizer *v);

#endif
