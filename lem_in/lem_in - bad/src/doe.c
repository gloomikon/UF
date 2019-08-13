/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:08:42 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/05 19:13:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_out_edges(t_lemin *lemin)
{
	t_vert	*curr;
	int		bfs_lvl;

	bfs_lvl = lemin->bfs_lvl + 1;
	while (--bfs_lvl && (curr = lemin->verts))
		while (curr)
		{
			(curr->output_links > 1 && curr->bfs_lvl == bfs_lvl) ?
			del_one_out_edge(lemin, curr) : 0;
			curr = curr->next;
		}
}

void	del_one_out_edge(t_lemin *lemin, t_vert *vert)
{
	int		min_l;
	int		curr_l;
	t_edge	*curr;
	t_edge	*best;

	curr = lemin->edges;
	best = NULL;
	min_l = INT_MAX;
	while (curr)
	{
		if (curr->start == vert
			&& min_l > (curr_l = count_length(lemin, curr, 0)))
		{
			best = curr;
			min_l = curr_l;
		}
		curr = curr->next;
	}
	del_another_out_edges(&lemin->edges, best);
	delete_dead_ends(lemin);
}

int		count_length(t_lemin *lemin, t_edge *edge, int l)
{
	return (edge->end == lemin->end) ?
	(l + 1) : count_length(lemin, lookfor_edge(lemin, edge->end, START), l + 1);
}

void	del_another_out_edges(t_edge **edges, t_edge *edge)
{
	t_edge	*curr;
	t_edge	*del;

	curr = *edges;
	while (curr)
	{
		del = curr;
		curr = curr->next;
		(del != edge && del->start == edge->start) ?
		delete_edge(edges, del) : 0;
	}
}
