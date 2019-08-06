/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/06 19:35:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "lem_in.h"

int		count_sum_of_routes(t_lemin *lemin, int n)
{
	int i;
	int sum;

	if (n == 0)
		return (0);
	i = -1;
	sum = 0;
	while (++i < n)
		sum += (lemin->routes[n].len - lemin->routes[i].len);
	return (sum);
}

void	prepare_ants(t_lemin *lemin)
{
	int i;

	lemin->ants = (t_vert**)ft_memalloc(sizeof(t_vert*) *
										lemin->ants_begin);
	i = -1;
	while (++i < lemin->ants_begin)
		lemin->ants[i] = lemin->start;

//	t_edge	*edge = lemin->edges;
//	while (edge)
//	{
//		printf("%p (%p)%s-%s(%p)\n", edge, edge->start,
//				edge->start->name, edge->end->name, edge->end);
//		edge = edge->next;
//	}
}

int 	find_free_route(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < lemin->start->output_links)
		if (lemin->routes[i].start->end == lemin->end
		|| lemin->routes[i].start->end->ant_number == 0)
			return (i);
	return (-1);
}

void	go_through_routes(t_lemin *lemin)
{
	long long i;
	int r;
	int j;
	t_edge	*tmp;

	i = -1;
	j = -1;
	while (lemin->end->ant_number != lemin->ants_begin && (i = -1))
	{
		lemin->lines += 1;
		while (++i < lemin->ants_begin)
		{
			if (lemin->ants[i] == lemin->start
				&& (r = find_free_route(lemin)) != -1
				&& lemin->ants_left > count_sum_of_routes(lemin, r))
			{
				lemin->ants[i] = lemin->routes[r].start->end;
				ft_printf("L%d-%s ", i + 1, lemin->ants[i]->name);
				lemin->ants[i]->ant_number += 1;
				lemin->ants_left -= 1;
			}
			else if (lemin->ants[i] != lemin ->start
			&& lemin->ants[i] != lemin->end)
			{
				lemin->ants[i]->ant_number -= 1;
				tmp = lookfor_edge(lemin, lemin->ants[i], START);
				lemin->ants[i] = tmp->end;
				ft_printf("L%d-%s ", i + 1, lemin->ants[i]->name);
				lemin->ants[i]->ant_number += 1;
			}
		}
		ft_printf("\n");
	}
}

void	sort_routes(t_lemin *lemin)
{
	int		m;
	int		i;
	int 	j;
	t_route	tmp;

	i = -1;
	while (++i < lemin->start->output_links
		&& (j = i) == i && (m = i) == i)
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

/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;

	if (argc == 2)
		(void)(argv);
	ft_bzero(&lemin, sizeof(t_lemin));
	read_data(&lemin);
	main_algo(&lemin);

	ft_printf("\nRESULT: %d lines\n", lemin.lines);
	system("leaks -q a.out");
	return (0);
}
