/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_score_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:38:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:54:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

char	*create_score_line(int player, t_visualizer *v)
{
	char	*line;
	char	*tmp;
	char	*stmp;
	int		percent;

	line = ft_itoa(player == 1 ? v->scores.x : v->scores.y);
	percent = (int)((double)(player == 1 ? v->scores.x : v->scores.y) /
		(MX * MY) * 100);
	stmp = ft_itoa(percent);
	tmp = ft_strjoin(line, "  ");
	ft_strdel(&line);
	line = ft_strjoin(tmp, stmp);
	ft_strdel(&tmp);
	ft_strdel(&stmp);
	tmp = ft_strjoin(line, "%");
	ft_strdel(&line);
	return (tmp);
}
