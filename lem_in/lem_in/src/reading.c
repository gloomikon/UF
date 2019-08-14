/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 17:03:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_matrix(t_lemin *lemin)
{
	int	i;

	i = -1;
	lemin->matrix = (int**)malloc(sizeof(int*) * lemin->verts_count);
	while (++i < lemin->verts_count)
		lemin->matrix[i] = (int*)ft_memalloc(sizeof(int) * lemin->verts_count);
}

void	read_data(t_lemin *lemin)
{
	char *line;

	read_ants(lemin);
	read_vertices(lemin, &line);
	(!lemin->start || !lemin->end) ?
	err_exit(lemin->beauty & LEAKS, "No start or end room") : 0;
	create_matrix(lemin);
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
			|| (lemin->ants_begin = ft_atoi(line)) < 1
			|| (lemin->ants_begin > INT_MAX))
				err_exit(lemin->beauty & LEAKS, "Ants number is invalid");
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
				err_exit(lemin->beauty & LEAKS, "Command duplicate");
		}
		else if (room(*line))
		{
			check_vert(lemin, (vert = create_vert(*line, type_of_vert, lemin->verts_count)));
			add_vert_to_lst(lemin, vert);
			lemin->verts_count += 1;
			type_of_vert = MID;
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
