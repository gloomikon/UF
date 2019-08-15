/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:34:22 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/15 15:45:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	sort_paths(t_paths *list)
{
	t_paths	*left;
	t_paths	*right;
	t_paths	*tmp;

	tmp = list;
	while (list->next)
	{
		if (list->len > list->next->len)
		{
			left = list->prev;
			right = list->next->next;
			left ? left->next = list->next : 0;
			right ? right->prev = list : 0;
			list->next->next = list;
			list->next->prev = left;
			list->prev = list->next;
			list->next = right;
			list = tmp;
		}
		list = list->next;
	}
}

void	relax(t_lemin *lemin, t_queue *q, int parent, int child)
{
	if (lemin->verts_arr[parent]->splitted == FALSE
	|| (lemin->verts_arr[parent]->splitted == TRUE
		&& lemin->verts_arr[parent]->next
		&& (lemin->verts_arr[parent]->next->splitted == TRUE
			|| lemin->matrix[parent][child] < 0)))
	{
		lemin->verts_arr[child]->next = lemin->verts_arr[parent];
		queue_push(&q, lemin->verts_arr[child]);
		lemin->verts_arr[child]->closed = TRUE;
	}
}

t_queue	*bfs(t_lemin *lemin, int *len)
{
	t_queue	*q;
	int		parent;
	int		child;

	q = new_queue(lemin->start);
	lemin->start->closed = 1;
	while (q->top != lemin->end)
	{
		parent = q->top->number;
		child = -1;
		while (++child < lemin->verts_count)
			(lemin->matrix[parent][child] && !lemin->verts_arr[child]->closed) ?
			relax(lemin, q, parent, child) : 0;
		queue_pop(&q);
		if (!q)
		{
			update_info(lemin);
			return (NULL);
		}
	}
	while (q)
		queue_pop(&q);
	return (create_path(lemin, len));
}

t_paths	*check_paths(t_lemin *lemin, t_paths *path_list, int *turns)
{
	static int	start = 0;


}

t_paths	*find_best(t_lemin *lemin, t_paths path_list)
{
	int		best_turns;
	t_paths	*best_path;
	int		curr_turns;
	t_paths	*curr_path;
	t_path	*p;

	p = path_list;
	best_path = check_paths(lemin, p, &best_turns);
}

void	find_solution(t_lemin *lemin)
{
	t_queue	*path;
	t_paths	*path_list;
	int		len;

	path_list = NULL;
	while ((path = bfs(lemin, &len)))
		add_path(&path_list, path, len);
	(!path_list) ? err_exit(lemin->beauty & LEAKS, "No path") : 0;
	while (path_list->prev)
		path_list = path_list->prev;
	sort_paths(path_list);
	lemin->paths = find_best(lemin, path_list);
}
