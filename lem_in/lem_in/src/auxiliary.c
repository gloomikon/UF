/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 18:00:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit(int leaks, char *error)
{
	leaks ? system("leaks -q lem_in") : 0;
	ft_printf("%s\n", error);
	exit(1);
}

t_vert	*find_vert(t_lemin *lemin, char *line)
{
	int	i;

	i = -1;
	while (++i < lemin->verts_count)
		if (!ft_strcmp(lemin->verts_arr[i]->name, line))
		{
			ft_strdel(&line);
			return (lemin->verts_arr[i]);
		}	
	ft_strdel(&line);
	return (NULL);
}

// t_edge	*init_link(t_vert *start, t_vert *end)
// {
// 	t_edge	*edge;

// 	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
// 	edge->next = NULL;
// 	edge->start = start;
// 	edge->end = end;
// 	return (edge);
// }

// t_edge	*lookfor_edge(t_lemin *lemin, t_vert *vert, int type)
// {
// 	t_edge	*curr;

// 	curr = lemin->edges;
// 	while (curr)
// 	{
// 		if (curr->start == vert && type == START)
// 			return (curr);
// 		else if (curr->end == vert && type == END)
// 			return (curr);
// 		curr = curr->next;
// 	}
// 	return (NULL);
// }
