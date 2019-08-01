/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:21:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/01 15:27:34 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		command(char *str)
{
	if (!ft_strncmp(str, "##", 2))
	{
		if (!ft_strcmp(str, "##start"))
			return (START);
		else if (!ft_strcmp(str, "##end"))
			return (END);
		else
			return (MID);
	}
	return (0);
}

int		comment(char **str)
{
	int res;

	res = 0;
	if (!command(*str) && !ft_strncmp(*str, "#", 1))
		res = 1;
	if (res)
		ft_strdel(str);
	return (res);
}

int		room(char *str)
{
	int		result;
	char	**split;

	result = 0;
	split = ft_strsplit(str, ' ');
	if (ft_strsplit_len(split) == 3
		&& split[0][0] != 'L'
		&& split[0][0] != '#'
		&& ft_isnumber(split[1], 10)
		&& ft_isnumber(split[2], 10))
		result = 1;
	ft_free_split_array(split);
	return (result);
}

void	check_vert(t_lemin *lemin, t_vert *vert)
{
	t_vert	*verts;

	verts = lemin->verts;
	while (verts)
	{
		if (vert != verts
			&& (!ft_strcmp(vert->name, verts->name)
				|| (vert->x == verts->x && vert->y == verts->y)))
			err_exit(NULL);
		verts = verts->next;
	}
}

void	check_edge(t_lemin *lem_in, t_edge *edge)
{
	t_edge	*edges;

	edges = lem_in->edges;
	while (edges)
	{
		if (edge != edges &&
		((!ft_strcmp(edge->start->name, edges->start->name)
		&& !ft_strcmp(edge->end->name, edges->end->name)) ||
		(!ft_strcmp(edge->start->name, edges->end->name)
		&& !ft_strcmp(edge->end->name, edges->start->name))))
			err_exit(NULL);
		edges = edges->next;
	}
}
