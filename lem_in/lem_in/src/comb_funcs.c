/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:45:07 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/20 19:11:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_path(t_comb *comb, int verts)
{
	comb->paths_arr[comb->count] = (t_path*)malloc(sizeof(t_path));
	comb->paths_arr[comb->count]->len = verts - 1;
	comb->paths_arr[comb->count]->verts_arr =
			(t_vert**)ft_memalloc(sizeof(t_vert*) * verts);
}

int		add_path(t_lemin *lemin)
{
	t_vert	*tmp;

	init_path(lemin->comb, lemin->end->len + 1);
	tmp = lemin->end;
	while (tmp
			&& (lemin->comb->paths_arr[lemin->comb->count]->
			verts_arr[(lemin->end->len)--] = tmp))
	{
		if (tmp != lemin->end && tmp != lemin->start)
			tmp->used = true;
		tmp = tmp->parent;
	}
	lemin->comb->count += 1;
	return (1);
}

void	count_max_paths(t_lemin *lemin)
{
	int	i;
	int	j;
	int	output;
	int	input;

	input = 0;
	output = 0;
	j = -1;
	i = lemin->start->number;
	while (++j < lemin->verts_count)
		(lemin->matrix[i][j]) && (++output);
	j = lemin->end->number;
	i = -1;
	while (++i < lemin->verts_count)
		(lemin->matrix[i][j]) && (++input);
	lemin->max_paths = ft_min(input, output);
}

t_comb	*init_combination(int max_paths)
{
	t_comb	*combination;

	combination = (t_comb*)ft_memalloc(sizeof(t_comb));
	combination->paths_arr = (t_path**)ft_memalloc(sizeof(t_path*) * max_paths);
	return (combination);
}
