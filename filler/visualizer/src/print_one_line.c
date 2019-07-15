/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:36:10 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:41:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	print_one_line(char *line, int i, t_visualizer *v)
{
	int	j;

	j = 3;
	while (++j < 4 + MX)
	{
		wattron(v->map, COLOR_PAIR(7));
		if (line[j] == 'x')
			wattron(v->map, COLOR_PAIR(!strcmp(v->p2, "mzhurba.filler") ?
				1 : 2));
		else if (line[j] == 'o')
			wattron(v->map, COLOR_PAIR(!strcmp(v->p1, "mzhurba.filler") ?
				1 : 2));
		if (line[j] == 'X' || line[j] == 'x')
		{
			mvwaddstr(v->map, i + 1, 2 * j - 6,
				!strcmp(v->p2, "mzhurba.filler") ? ME : BOT);
			++v->scores.y;
		}
		else if (line[j] == 'O' || line[j] == 'o')
		{
			mvwaddstr(v->map, i + 1, 2 * j - 6,
				!strcmp(v->p1, "mzhurba.filler") ? ME : BOT);
			++v->scores.x;
		}
	}
}
