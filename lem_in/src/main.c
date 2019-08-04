/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/04 14:01:24 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_edge(t_edge **edges, t_edge *edge)
{
	t_edge	*prev;
	t_edge	*curr;

	prev = NULL;
	curr = *edges;
	while (curr && curr != edge)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!prev && curr)
		*edges = curr->next;
	else if (curr)
		prev->next = curr->next;
	(edge->start->output_links > 0) ? edge->start->output_links-- : 0;
	(edge->end->input_links > 0) ? edge->end->input_links-- : 0;
	free(edge);
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

void		orient_edges(t_edge *edges)
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


/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;

	if (argc == 2)
		(void)(argv);
	ft_bzero(&lemin, sizeof(t_lemin));
	read_data(&lemin);
	breadth_first_search(&lemin);
	delete_useless_edges(&lemin.edges);
	orient_edges(lemin.edges);
	count_input_output_edges(lemin.edges);
	delete_dead_ends(&lemin);


	printf("SUCCESS\n");
	print_data(&lemin);
	system("leaks -q a.out");
}
