/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:41:23 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/06 19:55:10 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	main_algo(t_lemin *lemin)
{
	breadth_first_search(lemin);
	delete_useless_edges(&lemin->edges);
	orient_edges(lemin->edges);
	count_input_output_edges(lemin->edges);
	delete_dead_ends(lemin);
	delete_in_edges(lemin);
	delete_out_edges(lemin);
	create_routes(lemin);
	sort_routes(lemin);
	prepare_ants(lemin);
	go_through_routes(lemin);
}

void	delete_useless_edges(t_edge **edges)
{
	t_edge	*del;
	t_edge	*curr;

	curr = *edges;
	while (curr)
	{
		del = curr;
		if (del->start->bfs_lvl == del->end->bfs_lvl
			|| del->start->bfs_lvl == -1
			|| del->end->bfs_lvl == -1)
			delete_edge(edges, del);
		curr = curr->next;
	}
}

void	orient_edges(t_edge *edges)
{
	t_edge	*curr;
	t_vert	*tmp;

	curr = edges;
	while (curr)
	{
		if (curr->start->bfs_lvl > curr->end->bfs_lvl)
		{
			tmp = curr->start;
			curr->start = curr->end;
			curr->end = tmp;
		}
		curr = curr->next;
	}
}

void	count_input_output_edges(t_edge *edges)
{
	t_edge *curr;

	curr = edges;
	while (curr)
	{
		curr->end->input_links++;
		curr->start->output_links++;
		curr = curr->next;
	}
}

void	delete_dead_ends(t_lemin *lemin)
{
	t_edge	*curr;
	t_edge	*del;
	int		repeat;

	repeat = 1;
	while (repeat)
	{
		repeat = 0;
		curr = lemin->edges;
		while (curr)
		{
			del = curr;
			if (((del->start != lemin->start
			&& del->start->input_links == 0 && del->start->output_links > 0)
			|| (del->end != lemin->end
			&& del->end->input_links > 0 && del->end->output_links == 0))
			&& (repeat = 1))
				delete_edge(&lemin->edges, del);
			curr = curr->next;
		}
	}
}
