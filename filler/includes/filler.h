/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:01:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 22:01:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "header.h"

# define DOWN	filler->board.height - 1
# define UP		0
# define RIGHT	filler->board.width - 1
# define LEFT	0
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	t_point		start;
	char		symbol;
}				t_player;

typedef struct	s_object
{
	int			height;
	int			width;
	int			size;
	char		**info;
}				t_object;

typedef struct	s_filler
{
	int			inited;
	t_player	me;
	t_player	bot;
	t_object	board;
	t_object	piece;
	t_point		target;
	t_point		*buf_player;
	t_point		*buf_enemy;
	t_point		count;		// x for player |  y for enemy
}				t_filler;

int		get_player(t_filler *filler);
void	filler_loop(t_filler *filler);

#endif	