/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:56:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/05 19:12:23 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_in_edges(t_lemin *lemin)
{
	t_vert	*curr;
	int		bfs_lvl;

	bfs_lvl = 0;
	while (++bfs_lvl < lemin->bfs_lvl + 1 && (curr = lemin->verts))
		while (curr)
		{
			if (curr->input_links > 1 && curr->bfs_lvl == bfs_lvl)
				del_one_in_edge(lemin, curr);
			curr = curr->next;
		}
}

void	del_one_in_edge(t_lemin *lemin, t_vert *vert)
{
	t_edge	*del;
	t_edge	*curr;

	curr = lemin->edges;
	while (vert->input_links > 1 && curr && (del = curr))
	{
		if (del->end == vert)
		{
			route_has_out_edge(lemin, del) ? delete_edge(&lemin->edges, del) :
			del_another_in_edge(&lemin->edges, del);
			delete_dead_ends(lemin);
		}
		curr = curr->next;
	}
}

int		route_has_out_edge(t_lemin *lemin, t_edge *edge)
{
	if (edge->start == lemin->start)
		return (0);
	return (edge->start->output_links > 1) ?
	1 : route_has_out_edge(lemin, lookfor_edge(lemin, edge->start, END));
}

void	del_another_in_edge(t_edge **edges, t_edge *edge)
{
	t_edge	*curr;
	t_edge	*del;

	curr = *edges;
	while (curr)
	{
		del = curr;
		(del != edge && del->end == edge->end) ?
		delete_edge(edges, del) : 0;
		curr = curr->next;
	}
}
