/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/04 13:05:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//void	create_ants(t_lemin *lemin)
//{
//	int i;
//
//	i = -1;
//	lemin->ants = (t_ant*)ft_memalloc(sizeof(t_ant) * lemin->ants_begin);
//	while (++i < lemin->ants_begin)
//		lemin->ants[i].start = lemin->start;
//}

void	print_data(t_lemin *lemin)
{
	t_vert	*verts;
	t_edge	*edges;

	verts = lemin->verts;
	edges = lemin->edges;
	ft_printf("%lld\n", lemin->ants_begin);
	while (verts)
	{
		if (verts->type % 2)
			verts->type == END ? ft_printf("##end\n") : ft_printf("##start\n");
		ft_printf("%s %d %d\n", verts->name, verts->x, verts->y);
		verts = verts->next;
	}
	while (edges)
	{
		printf("%s-%s\n", edges->start->name, edges->end->name);
		edges = edges->next;
	}
	printf("\n");
}

void	breadth_first_search(t_lemin *lemin)
{
	t_queue	*curr;
	t_queue *queue;

	lemin->start->bfs_lvl = 0;
	queue = NULL;
	queue_push_elem(&queue, queue_create_elem(lemin->start));
	while (queue)
	{
		curr = queue_get_curr_elem(&queue);
		if (curr->vert == lemin->end)
			lemin->end->bfs_lvl = INT_MAX;
		else
		{
			queue_update(&queue, curr->vert, lemin->edges);
			lemin->bfs_lvl = curr->vert->bfs_lvl;
		}
		free(curr);
	}
	lemin->end->bfs_lvl == -1 ? err_exit(NULL) : print_data(lemin);
}

/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;
	t_vert *vert;

	ft_bzero(&lemin, sizeof(t_lemin));
	read_data(&lemin);
	breadth_first_search(&lemin);
	//create_ants(&lemin);
	printf("SUCCESS\n");
	vert = lemin.verts;
	while (vert)
	{
		printf("%s %d\n", vert->name, vert->bfs_lvl);
		vert = vert->next;
	}
	system("leaks -q a.out");
}
