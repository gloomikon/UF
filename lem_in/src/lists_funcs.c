/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:11:10 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 15:24:34 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_vert_to_lst(t_lemin *lemin, t_vert *vert)
{
	t_vert *current;

	if ((current = lemin->verts))
	{
		while (current->next)
			current = current->next;
		current->next = vert;
	}
	else
		lemin->verts = vert;
	(vert->type == START) ? lemin->start = vert : 0;
	(vert->type == END) ? lemin->end = vert : 0;
}

t_vert	*create_vert(char *str, int type)
{
	char	**split;
	t_vert	*vert;

	split = ft_strsplit(str, ' ');
	vert = (t_vert *)ft_memalloc(sizeof(t_vert));
	vert->name = ft_strdup(split[0]);
	vert->type = type;
	vert->x = ft_atoi(split[1]);
	vert->y = ft_atoi(split[2]);
	vert->input_links = 0;
	vert->output_links = 0;
	vert->bfs_lvl = -1;
	vert->ant_number = 0;
	vert->next = NULL;
	ft_free_split_array(split);
	return (vert);
}

t_edge	*create_edge(t_lemin *lemin, char **str)
{
	char	*dash;
	char	*start_name;
	char	*end_name;
	t_vert	*start_vert;
	t_vert	*end_vert;

	dash = ft_strchr(*str + 1, '-');
	if (!dash)
		err_exit(lemin->beauty & LEAKS);
	if (!(start_name = ft_strsub(*str, 0, dash - *str)))
		err_exit(lemin->beauty & LEAKS);
	if (!(end_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
	{
		ft_strdel(&start_name);
		err_exit(lemin->beauty & LEAKS);
	}
	if ((start_vert = find_vert(lemin, start_name))
	&& (end_vert = find_vert(lemin, end_name)))
		return (init_link(start_vert, end_vert));
	return (NULL);
}

void	add_edge_to_lst(t_lemin *lemin, t_edge *edge)
{
	t_edge	*current;

	current = lemin->edges;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = edge;
	}
	else
		lemin->edges = edge;
}
