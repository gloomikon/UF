/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/20 19:14:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_data(t_lemin *lemin)
{
	char	*line;
	t_vert	*verts;

	read_ants(lemin);
	verts = NULL;
	read_vertices(lemin, &line, &verts);
	(!lemin->start || !lemin->end) && (free_verts_list(&verts)) &&
	err_exit(lemin->beauty & LEAKS, "No start or end room");
	create_adjacency_matrix(lemin, verts);
	read_edges(lemin, &line);
	(!lemin->edges) ? err_exit(lemin->beauty & LEAKS, "No edges") : 0;
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
			|| (lemin->ants = ft_atoi(line)) < 1
			|| (lemin->ants > INT_MAX))
				err_exit(lemin->beauty & LEAKS, "Ants number is invalid");
			break ;
		}
	}
}

void	read_vertices(t_lemin *lemin, char **line, t_vert **verts)
{
	int		type;
	t_vert	*vert;

	type = MID;
	while ((*line = read_line(lemin)))
	{
		if (comment(*line))
			type = MID;
		else if (command(*line))
		{
			type = command(*line);
			((type == START && lemin->start) || (type == END && lemin->end))
				&& err_exit(lemin->beauty & LEAKS, "Command duplicate");
		}
		else if (room(*line))
		{
			if (!(check_vert(*verts,
			(vert = create_vert(*line, lemin->verts_count)))))
				err_exit(lemin->beauty & LEAKS, "Duplicate room");
			add_vert_to_lst(lemin, verts, vert, type);
			type = MID;
		}
		else
			break ;
	}
}

void	read_edges(t_lemin *lemin, char **line)
{
	t_vert	*a;
	t_vert	*b;

	while (*line || (*line = read_line(lemin)))
	{
		if (comment(*line))
			*line = NULL;
		else if (command(*line))
		{
			if (command(*line) % 2)
				err_exit(lemin->beauty & LEAKS,
					"Invalid command in edges");
			else
				*line = NULL;
		}
		else
		{
			check_edge(lemin, line, &a, &b);
			add_edge(lemin, a, b);
			*line = NULL;
		}
	}
}
