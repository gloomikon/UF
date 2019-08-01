/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/01 15:28:15 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit(char **str)
{
	str ? ft_strdel(str) : 0;
	system("leaks -q a.out");
	ft_printf("ERROR\n");
	exit(1);
}

t_vert	*find_vert(t_lemin *lemin, char *line)
{
	t_vert	*current;

	current = lemin->verts;
	while (current)
	{
		if (!ft_strcmp(current->name, line))
		{
			ft_strdel(&line);
			return (current);
		}
		current = current->next;
	}
	ft_strdel(&line);
	return (NULL);
}

t_edge	*init_link(t_vert *start, t_vert *end)
{
	t_edge	*edge;

	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	edge->next = NULL;
	edge->prev = NULL;
	edge->start = start;
	edge->end = end;
	return (edge);
}
