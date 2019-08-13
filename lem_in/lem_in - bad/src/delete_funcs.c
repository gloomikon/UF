/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:54:23 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/05 17:54:34 by mzhurba          ###   ########.fr       */
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
