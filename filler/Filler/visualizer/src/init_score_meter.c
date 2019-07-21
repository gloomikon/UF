/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_score_meter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:32:53 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:56:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_score_meter(t_visualizer *v)
{
	v->score = newwin(7, (MX + 2) * 2, 10,
		v->map_size.x > 17 ? 5 : 7);
	wattron(v->score, A_BOLD);
	wattron(v->score, ft_strcmp(v->p1, "mzhurba.filler") ?
		COLOR_PAIR(5) : COLOR_PAIR(4));
	mvwaddstr(v->score, 1, 2 + (MX - ft_strlen(v->p1)) / 2, v->p1);
	wattron(v->score, ft_strcmp(v->p1, "mzhurba.filler") ?
		COLOR_PAIR(4) : COLOR_PAIR(5));
	mvwaddstr(v->score, 1,
	1 + MX * 2 - (MX / 2) - ft_strlen(v->p2) / 2, v->p2);
	wattron(v->score, COLOR_PAIR(14));
	box(v->score, 0, 0);
	wrefresh(v->score);
	wattroff(v->score, COLOR_PAIR(14));
}
