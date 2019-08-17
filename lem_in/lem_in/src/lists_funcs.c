/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:11:10 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/15 15:47:19 by mzhurba          ###   ########.fr       */
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
	lemin->verts_count += 1;
}

t_vert	*create_vert(char *str, int type, int number)
{
	char	**split;
	t_vert	*vert;

	split = ft_strsplit(str, ' ');
	vert = (t_vert *)ft_memalloc(sizeof(t_vert));
	vert->name = ft_strdup(split[0]);
	vert->number = number;
	vert->type = type;
	vert->x = ft_atoi(split[1]);
	vert->y = ft_atoi(split[2]);
	vert->len = INT_MAX;
	vert->next = NULL;
	ft_free_split_array(split);
	return (vert);
}

void	check_edge(t_lemin *lemin, char **str, t_vert **a, t_vert **b)
{
	char	*dash;
	char	*start_name;
	char	*end_name;

	dash = ft_strchr(*str + 1, '-');
	if (!dash)
		err_exit(lemin->beauty & LEAKS, "No dash");
	if (!(start_name = ft_strsub(*str, 0, dash - *str)))
		err_exit(lemin->beauty & LEAKS, "Left room error");
	if (!(end_name = ft_strsub(dash + 1, 0, ft_strlen(dash + 1))))
	{
		ft_strdel(&start_name);
		err_exit(lemin->beauty & LEAKS, "Right room error");
	}
	if (!(*a = find_vert(lemin, start_name))
	|| !(*b = find_vert(lemin, end_name)))
		err_exit(lemin->beauty & LEAKS, "Room not found");
}

void	add_edge(t_lemin *lemin, t_vert *a, t_vert *b)
{
	if (lemin->matrix[a->number][b->number])
		err_exit(lemin->beauty & LEAKS, "Duplicate edge");
	lemin->matrix[a->number][b->number] = 1;
	lemin->matrix[b->number][a->number] = 1;
	lemin->edges = TRUE;
}
