/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/20 23:57:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_args(int argc, char **argv, t_lemin *lemin)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 2
		&& argv[i][0] == '-'
		&& ft_strchr(PROGRAM_FLAGS, argv[i][1]))
		{
			!ft_strcmp(argv[i], "-i") && (lemin->beauty |= INPUT);
			!ft_strcmp(argv[i], "-r") && (lemin->beauty |= RESULT);
			!ft_strcmp(argv[i], "-c") && (lemin->beauty |= COLOR);
			!ft_strcmp(argv[i], "-p") && (lemin->beauty |= PATHS);
			!ft_strcmp(argv[i], "-e") && (lemin->beauty |= EMOJI);
			!ft_strcmp(argv[i], "-l") && (lemin->beauty |= LEAKS);
			!ft_strcmp(argv[i], "-h") && (lemin->beauty |= HELP);
		}
		else
			err_exit(lemin->beauty & LEAKS, "Invalid flag");
	}
}

int		dijkstra(t_lemin *lemin)
{
	int		i;
	int		min;
	t_vert	*vert;

	lemin->start->len = 0;
	while ((i = -1)
			&& (min = INT_MAX)
			&& !(vert = NULL))
	{
		while (++i < lemin->verts_count)
			if (!lemin->verts[i]->visited && !(lemin->verts[i]->used)
				&& lemin->verts[i]->len < min && (vert = lemin->verts[i]))
				min = lemin->verts[i]->len;
		if ((i = -1) && !vert)
			break ;
		while (++i < lemin->verts_count)
			(lemin->matrix[vert->number][i]
			&& lemin->verts[i]->len > vert->len + 1
			&& (lemin->verts[i]->len = vert->len + 1)
			&& (lemin->verts[i]->parent = vert));
		(vert->visited = true);
	}
	if (!lemin->end->parent)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_lemin	lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	read_args(argc, argv, &lemin);
	if (lemin.beauty & HELP)
		print_help();
	else
	{
		read_data(&lemin);
		lemin.comb = init_combination(lemin.max_paths);
		while (dijkstra(&lemin))
		{
			add_path(&lemin) && annul(&lemin);
			if (lemin.comb->paths_arr[0]->len == 1)
				break ;
		}
		if (lemin.comb->count == 0)
			err_exit(lemin.beauty & LEAKS, "No paths");
		(lemin.beauty & INPUT) ? 0 : print_input(&lemin);
		(lemin.beauty & PATHS) ? print_comb(&lemin) : 0;
		go_through_routes(&lemin);
		(lemin.beauty & RESULT) ? print_result(&lemin) : 0;
		(lemin.beauty & LEAKS) ? system("leaks -q lem-in") : 0;
	}
	return (0);
}
