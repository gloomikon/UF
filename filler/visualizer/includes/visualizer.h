/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 03:35:48 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/12 04:24:42 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "header.h"
# include <curses.h>
# include <locale.h>

# define PLAYER1	"\xF0\x9F\x8D\x93"
# define PLAYER2	"\xF0\x9F\x8D\x8C"
# define DELAY		10000

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_visualizer
{
	WINDOW		*map;
	WINDOW		*score;
	int			size;
	t_point		map_size;
	t_point		scores;
	char		*p1;
	char		*p2;
}				t_visualizer;

#endif