/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_score_meter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:38:44 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:42:15 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	update_score_meter(t_visualizer *v)
{
	char	*s;
	int		p;
	int		i;

	wattron(v->score, A_UNDERLINE);
	s = create_score_line(1, v);
	mvwaddstr(v->score, 4, (MX - ft_strlen(s)) / 2, s);
	ft_strdel(&s);
	s = create_score_line(2, v);
	mvwaddstr(v->score, 4, MX * 2 - MX / 2 - ft_strlen(s) / 2, s);
	ft_strdel(&s);
	wattroff(v->score, A_UNDERLINE);
	p = (int)((double)v->scores.x / (MX * MY) * MX);
	i = -1;
	while (++i <= p)
		mvwaddstr(v->score, 3, 2 * (i + 1),
			!ft_strcmp(v->p1, "mzhurba.filler") ? ME : BOT);
	p = (int)((1 - (double)v->scores.y / (MX * MY)) * MX);
	while (++i < p)
		mvwaddch(v->score, 3, 2 * (i + 1), '.');
	while (++i < MX)
		mvwaddstr(v->score, 3, 2 * (i + 1),
			!ft_strcmp(v->p2, "mzhurba.filler") ? ME : BOT);
	wrefresh(v->score);
}
