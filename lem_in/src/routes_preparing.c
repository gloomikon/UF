/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes_preparing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:05:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 17:10:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	prepare_ants(t_lemin *lemin)
{
	int i;

	lemin->ants = (t_vert**)ft_memalloc(sizeof(t_vert*) *
										lemin->ants_begin);
	i = -1;
	while (++i < lemin->ants_begin)
		lemin->ants[i] = lemin->start;
}

void	create_routes(t_lemin *lemin)
{
	int		i;
	t_edge	*curr;
	t_edge	*tmp;

	i = -1;
	curr = lemin->edges;
	lemin->routes = (t_route*)ft_memalloc(sizeof(t_route) *
						lemin->start->output_links);
	while (curr)
	{
		if (curr->start == lemin->start)
		{
			tmp = curr;
			lemin->routes[++i].start = curr;
			lemin->routes[i].len = 1;
			while (tmp->end != lemin->end)
			{
				tmp = lookfor_edge(lemin, tmp->end, START);
				lemin->routes[i].len += 1;
			}
			if (i == lemin->start->output_links)
				break ;
		}
		curr = curr->next;
	}
}

void	sort_routes(t_lemin *lemin)
{
	int		m;
	int		i;
	int		j;
	t_route	tmp;

	i = -1;
	while (++i < lemin->start->output_links
		&& (j = i) == i
		&& (m = i) == i)
	{
		while (++j < lemin->start->output_links)
			if (lemin->routes[j].len < lemin->routes[m].len)
				m = j;
		if (m != i)
		{
			tmp = lemin->routes[i];
			lemin->routes[i] = lemin->routes[m];
			lemin->routes[m] = tmp;
		}
	}
}
