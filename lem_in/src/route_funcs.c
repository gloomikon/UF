/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:07:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 17:25:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			count_sum_of_routes(t_lemin *lemin, int n)
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

int			find_free_route(t_lemin *lemin)
{
	int i;

	i = -1;
	while (++i < lemin->start->output_links)
		if (lemin->routes[i].start->end == lemin->end
			|| lemin->routes[i].start->end->ant_number == 0)
			return (i);
	return (-1);
}

static void	generate_one_turn(long long *i, t_lemin *lemin)
{
	int		r;
	t_edge	*tmp;

	lemin->result += 1;
	while (++(*i) < lemin->ants_begin)
		if (lemin->ants[*i] == lemin->start
			&& (r = find_free_route(lemin)) != -1
			&& lemin->ants_left > count_sum_of_routes(lemin, r))
		{
			lemin->ants[*i] = lemin->routes[r].start->end;
			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
			ft_printf("%d-%s ", *i + 1, lemin->ants[*i]->name);
			lemin->ants[*i]->ant_number += 1;
			lemin->ants_left -= 1;
		}
		else if (lemin->ants[*i] != lemin->start
				&& lemin->ants[*i] != lemin->end)
		{
			lemin->ants[*i]->ant_number -= 1;
			tmp = lookfor_edge(lemin, lemin->ants[*i], START);
			lemin->ants[*i] = tmp->end;
			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
			ft_printf("%d-%s ", *i + 1, lemin->ants[*i]->name);
			lemin->ants[*i]->ant_number += 1;
		}
}

void		go_through_routes(t_lemin *lemin)
{
	long long	i;

	while (lemin->end->ant_number != lemin->ants_begin && (i = -1))
	{
		generate_one_turn(&i, lemin);
		ft_printf("\n");
	}
}
