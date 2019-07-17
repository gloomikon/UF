/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:43:03 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:56:12 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_winner(t_visualizer *v)
{
	char	*tmp;
	char	*result;
	int		i;

	tmp = ft_strnew(MX * 2 + 2);
	i = -1;
	while (++i < MX * 2 + 2)
		tmp[i] = ' ';
	wattron(v->score, COLOR_PAIR(15));
	mvwaddstr(v->score, 1, 1, tmp);
	ft_strdel(&tmp);
	tmp = ft_strjoin("--> ", v->scores.x > v->scores.y ? v->p1 : v->p2);
	result = ft_strjoin(tmp, " <--");
	mvwaddstr(v->score, 1, 2 + (MX * 2 - ft_strlen(result)) / 2, result);
	ft_strdel(&tmp);
	ft_strdel(&result);
	wrefresh(v->score);
}
