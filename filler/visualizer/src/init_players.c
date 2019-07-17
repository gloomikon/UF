/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:31:22 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:31:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_players(t_visualizer *v)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		free(line);
	}
	get_next_line(0, &line);
	v->p1 = ft_strdup(ft_strrchr(line, '/') + 1);
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	v->p2 = ft_strdup(ft_strrchr(line, '/') + 1);
	free(line);
}
