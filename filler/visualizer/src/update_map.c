/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:37:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:41:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	update_map(t_visualizer *v)
{
	char	*line;
	int		i;

	ft_bzero(&v->scores, sizeof(t_point));
	i = -1;
	while (++i < MY)
	{
		get_next_line(0, &line);
		print_one_line(line, i, v);
		ft_strdel(&line);
	}
	wrefresh(v->map);
}
