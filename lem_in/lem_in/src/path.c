/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:35:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/15 15:44:24 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//void	add_path(t_paths **path_list, t_queue *path, int len)
//{
//	t_paths	*new;
//
//	new = (t_paths*)malloc(sizeof(t_paths));
//	new->path = path;
//	new->len = len;
//	new->len0 = len;
//	new->next = NULL;
//	new->prev = NULL;
//	if (*path_list)
//	{
//		while ((*path_list)->next)
//			*path_list = (*path_list)->next;
//		(*path_list)->next = new;
//		new->prev = *path_list;
//	}
//	else
//		*path_list = new;
//}
//
//t_queue	*create_path(t_lemin *lemin, int *len)
//{
//	t_vert	*track;
//	t_queue	*path;
//
//	*len = 0;
//	path = new_queue(lemin->end);
//	track = path->top->next;
//	while (track)
//	{
//		lemin->matrix[path->top->number][track->number] *= -1;
//		track->splitted = 1;
//		lemin->matrix[track->number][path->top->number] = 0;
//		queue_push_front(&path, track);
//		track = track->next;
//		++(*len);
//	}
//	lemin->start->splitted = 0;
//	while (path->prev)
//		path = path->prev;
//	update_info(lemin);
//	return (path);
//}
