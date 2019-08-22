/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/20 22:22:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_sum_of_paths(t_lemin *lemin, int n)
{
	int	i;
	int	sum;

	if (n == 0)
		return (0);
	i = -1;
	sum = 0;
	while (++i < n)
		sum += (lemin->comb->paths_arr[n]->len -
				lemin->comb->paths_arr[i]->len);
	return (sum);
}

int		find_free_path(t_lemin *lemin)
{
	int	i;

	i = -1;
	while (++i < lemin->comb->count)
		if (lemin->comb->paths_arr[i]->verts_arr[1] == lemin->end
			|| lemin->comb->paths_arr[i]->verts_arr[1]->ants == 0)
			return (i);
	return (-1);
}

void	generate_one_turn(int **ants, int *ants_left, t_lemin *lemin)
{
	int		r;
	int		i;

	i = -1;
	while (++i < lemin->ants)
		if (ants[i][0] == -1
			&& ((r = find_free_path(lemin)) != -1)
			&& ((*ants_left) > count_sum_of_paths(lemin, r)))
		{
			ants[i][0] = r;
			print_one_line(lemin, i + 1, lemin->comb->paths_arr[r]->
			verts_arr[(++ants[i][1])]->name) && (ants[i][0] = r);
			++(lemin->comb->paths_arr[r]->verts_arr[ants[i][1]]->ants);
			--(*ants_left);
		}
		else if (ants[i][0] != -1 && lemin->comb->paths_arr[ants[i][0]]->
				verts_arr[ants[i][1]] != lemin->end)
		{
			--(lemin->comb->paths_arr[ants[i][0]]->verts_arr[ants[i][1]]->ants);
			print_one_line(lemin, i + 1, lemin->comb->
			paths_arr[ants[i][0]]->verts_arr[(++ants[i][1])]->name);
			++(lemin->comb->paths_arr[ants[i][0]]->verts_arr[ants[i][1]]->ants);
		}
}

void	go_through_routes(t_lemin *lemin)
{
	int		i;
	int		**ants;
	int		ants_left;

	ants_left = lemin->ants;
	ants = (int**)malloc(sizeof(int*) * lemin->ants);
	i = -1;
	while (++i < lemin->ants)
		(ants[i] = (int*)ft_memalloc(sizeof(int) * 2))
		&& (ants[i][0] = -1);
	while (lemin->end->ants != lemin->ants)
	{
		lemin->result += 1;
		generate_one_turn(ants, &ants_left, lemin);
		ft_printf("\n");
	}
	i = -1;
	while (++i < lemin->ants)
		free(ants[i]);
	free(ants);
}
