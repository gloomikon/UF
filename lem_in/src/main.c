/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/05 19:59:17 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "lem_in.h"

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
	printf("SUCCESS\n");
	for (int i = 0; i < lemin.start->output_links; ++i)
	{
		printf("%d\t", lemin.routes[i].len);
		while (lemin.routes[i].start->end != lemin.end)
		{
			printf("%s-%s ", lemin.routes[i].start->start->name, lemin.routes[i].start->end->name);
			lemin.routes[i].start = lookfor_edge(&lemin, lemin.routes[i].start->end, START);
		}
		printf("\n");
	}
	system("leaks -q a.out");
	return (0);
}
