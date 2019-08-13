/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 16:57:54 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_data(t_lemin *lemin)
{
	char *line;

	read_ants(lemin);
	read_vertices(lemin, &line);
	(!lemin->start || !lemin->end) ? err_exit(lemin->beauty & LEAKS) : 0;
	read_edges(lemin, &line);
	lemin->ants_left = lemin->ants_begin;
	(!lemin->edges) ? err_exit(lemin->beauty & LEAKS) : 0;
}

void	read_ants(t_lemin *lemin)
{
	char	*line;

	while ((line = read_line(lemin)))
	{
		if (comment(line))
			;
		else
		{
			if (!ft_isnumber(line, 10)
			|| (lemin->ants_begin = ft_atoi(line)) < 1
			|| (lemin->ants_begin > INT_MAX))
				err_exit(lemin->beauty & LEAKS);
			break ;
		}
	}
}

void	read_vertices(t_lemin *lemin, char **line)
{
	int		type_of_vert;
	t_vert	*vert;

	type_of_vert = MID;
	while ((*line = read_line(lemin)))
	{
		if (comment(*line))
			type_of_vert = MID;
		else if (command(*line))
		{
			type_of_vert = command(*line);
			if ((type_of_vert == START && lemin->start)
				|| (type_of_vert == END && lemin->end))
				err_exit(lemin->beauty & LEAKS);
		}
		else if (room(*line))
		{
			check_vert(lemin, (vert = create_vert(*line, type_of_vert)));
			add_vert_to_lst(lemin, vert);
			type_of_vert = MID;
		}
		else
			break ;
	}
}

void	read_edges(t_lemin *lemin, char **line)
{
	t_edge	*edge;

	while (*line || (*line = read_line(lemin)))
	{
		if (comment(*line))
			*line = NULL;
		else if (command(*line))
		{
			if (command(*line) % 2)
				err_exit(lemin->beauty & LEAKS);
			else
				*line = NULL;
		}
		else
		{
			if (!(edge = create_edge(lemin, line)))
				err_exit(lemin->beauty & LEAKS);
			add_edge_to_lst(lemin, edge);
			check_edge(lemin, edge);
			*line = NULL;
		}
	}
}
