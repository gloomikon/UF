/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:26:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/04 12:27:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	queue_update(t_queue **queue, t_vert *vert, t_edge *edges)
{
	t_edge	*curr;
	t_vert	*target;

	target = NULL;
	curr = edges;
	while (curr)
	{
		if (curr->start == vert)
			target = curr->end;
		else if (curr->end == vert)
			target = curr->start;
		if (target)
		{
			if (target->bfs_lvl == -1)
			{
				target->bfs_lvl = vert->bfs_lvl + 1;
				queue_push_elem(queue, queue_create_elem(target));
			}
		}
		curr = curr->next;
	}
}

t_queue	*queue_get_curr_elem(t_queue **queue)
{
	t_queue		*elem;

	elem = NULL;
	if (queue && *queue)
	{
		elem = *queue;
		*queue = (*queue)->next;
	}
	return (elem);
}

void	queue_push_elem(t_queue **queue, t_queue *elem)
{
	t_queue	*curr;

	if (queue && *queue)
	{
		curr = *queue;
		while (curr->next)
			curr = curr->next;
		curr->next = elem;
	}
	else if (queue)
		*queue = elem;
}

t_queue	*queue_create_elem(t_vert *vert)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->vert = vert;
	queue->next = NULL;
	return (queue);
}
