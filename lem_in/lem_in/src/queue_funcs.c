/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:26:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/15 15:45:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
//
//t_queue	*new_queue(t_vert *start)
//{
//	t_queue *new;
//
//	new = (t_queue *)malloc(sizeof(t_queue));
//	new->top = start;
//	new->next = NULL;
//	new->prev = NULL;
//	return (new);
//}
//
//void	queue_push(t_queue **q, t_vert *vert)
//{
//	while ((*q)->next)
//		*q = (*q)->next;
//	(*q)->next = new_queue(vert);
//	(*q)->next->prev = *q;
//	(*q) = (*q)->next;
//}
//
//void	queue_pop(t_queue **q)
//{
//	while ((*q)->prev)
//		*q = (*q)->prev;
//	if ((*q)->next)
//		(*q) = (*q)->next;
//	if ((*q)->prev)
//	{
//		free((*q)->prev);
//		(*q)->prev = NULL;
//	}
//	else
//	{
//		free(*q);
//		*q = NULL;
//	}
//}
//
//void	queue_push_front(t_queue **q, t_vert *vert)
//{
//	while ((*q)->prev)
//		*q = (*q)->prev;
//	(*q)->prev = new_queue(vert);
//	(*q)->prev->next = *q;
//	(*q) = (*q)->prev;
//}
