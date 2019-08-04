/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:18:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/04 13:18:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_data(t_lemin *lemin)
{
	t_vert	*verts;
	t_edge	*edges;

	verts = lemin->verts;
	edges = lemin->edges;
	ft_printf("%lld\n", lemin->ants_begin);
	while (verts)
	{
		if (verts->type % 2)
			verts->type == END ? ft_printf("##end\n") : ft_printf("##start\n");
		ft_printf("%s %d %d\n", verts->name, verts->x, verts->y);
		verts = verts->next;
	}
	while (edges)
	{
		printf("%s-%s\n", edges->start->name, edges->end->name);
		edges = edges->next;
	}
	printf("\n");
}
