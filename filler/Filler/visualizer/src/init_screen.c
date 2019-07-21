/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:35:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:55:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_screen(char *line, t_visualizer *v)
{
	setlocale(LC_ALL, "");
	initscr();
	curs_set(0);
	v->size = COLS * LINES;
	read_size(line, v);
	refresh();
	colorizer();
	init_header(v);
	init_score_meter(v);
	init_map(v);
}
