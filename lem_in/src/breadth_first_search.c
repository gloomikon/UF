/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:35:03 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 15:38:42 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	lemin->end->bfs_lvl == -1 ? err_exit(lemin->beauty & LEAKS) : 0;
}
