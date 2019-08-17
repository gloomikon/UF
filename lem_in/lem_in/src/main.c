/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/17 19:38:57 by mzhurba          ###   ########.fr       */
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
			!ft_strcmp(argv[i], "-i") ? lemin->beauty |= INPUT : 0;
			!ft_strcmp(argv[i], "-r") ? lemin->beauty |= RESULT : 0;
			!ft_strcmp(argv[i], "-c") ? lemin->beauty |= COLOR : 0;
			!ft_strcmp(argv[i], "-p") ? lemin->beauty |= PATHS : 0;
			!ft_strcmp(argv[i], "-e") ? lemin->beauty |= EMOJI : 0;
			!ft_strcmp(argv[i], "-l") ? lemin->beauty |= LEAKS : 0;
			!ft_strcmp(argv[i], "-h") ? lemin->beauty |= HELP : 0;
		}
		else
			err_exit(lemin->beauty & LEAKS, "Invalid flag");
	}
}

int		**create_copy(t_lemin *lemin)
{
	int 	**matrix;
	int 	i;
	int 	j;

	matrix = (int**)malloc(sizeof(int*) * lemin->verts_count);
	i = -1;
	while (++i < lemin->verts_count && (j = -1))
	{
		(matrix[i] = (int*)malloc(sizeof(int*) * lemin->verts_count));
		while (++j < lemin->verts_count)
			matrix[i][j] = lemin->matrix[i][j];
	}
	return (matrix);
}

int		count_result(int ants, t_vert ***combination)
{
	int		sum_of_lens;
	int		paths;
	int		verts;

	paths = -1;
	verts = -1;
	sum_of_lens = 0;
	while (combination[++paths])
	{
		while (combination[paths][verts])
			++verts;
		sum_of_lens += verts;
	}
	return ((ants + sum_of_lens - 1) / paths);
}

void	init_paths(t_lemin *lemin)
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
	lemin->path_count = ft_min(input, output);
	lemin->paths = (t_vert****)malloc(sizeof(t_vert***) * lemin->path_count);
	lemin->paths[0] = (t_vert***)malloc(sizeof(t_vert**));
	lemin->paths[0][0] = (t_vert**)ft_memalloc(sizeof(t_vert*) *
												lemin->verts_count);
	lemin->path_lens = (int*)malloc(sizeof(int) * lemin->path_count);
	i = -1;
	while (++i < lemin->path_count)
		lemin->path_lens[i] = INT_MAX;
	lemin->path_lens[0] = count_result(lemin->ants, lemin->paths[0]);
}

void	dejkstra(t_lemin *lemin)
{
	int i;
	int min;
	t_vert	*vert;

	lemin->start->len = 0;
	while ((i = -1) && (min = INT_MAX) && !(vert = NULL))
	{
		while (++i < lemin->verts_count)
			if (!lemin->verts_arr[i]->visited
				&& lemin->verts_arr[i]->len < min
				&& (vert = lemin->verts_arr[i]))
				min = lemin->verts_arr[i]->len;
		if (!vert)
			break;
		i = -1;
		while (++i < lemin->verts_count)
			(lemin->matrix[vert->number][i]
			&& lemin->verts_arr[i]->len > vert->len + 1
			&& (lemin->verts_arr[i]->len = vert->len + 1)
			&& (lemin->verts_arr[i]->parent = vert));
		(vert->visited = true);
	}
	if (!lemin->end->parent)
		err_exit(false, "No path!");
}

void	annul(t_lemin *lemin)
{
	int	i;

	i = -1;
	while (++i < lemin->verts_count)
		!(lemin->verts_arr[i]->len = 0)
		&& (lemin->verts_arr[i]->parent = NULL);
}

void	create_dejkstra_path(t_lemin *lemin)
{
	int	len;
	t_vert	*curr;

	curr = lemin->end;
	len = lemin->end->len;
	while (curr)
	{
		lemin->paths[0][0][len--] = curr;
		curr = curr->parent;
	}
	annul(lemin);
}

int		main(int argc, char **argv)
{
	t_lemin	lemin;
	int 	**copy;

	ft_bzero(&lemin, sizeof(t_lemin));
	read_args(argc, argv, &lemin);
	if (lemin.beauty & HELP)
		print_help();
	else
	{
		read_data(&lemin);
		copy = create_copy(&lemin);
		dejkstra(&lemin);
		init_paths(&lemin);
		create_dejkstra_path(&lemin);
		int i = -1;
		while (lemin.paths[0][0][++i])
			ft_printf("%s -> \n", lemin.paths[0][0][i]->name);
//		for (int i = 0; i < lemin.verts_count; ++i)
//		{
//			if (!(lemin.paths[0][0][i]))
//				break;
//			ft_printf("%s -> \n", lemin.paths[0][0][i]->name);
//		}
//		for (int i = 0; i < lemin.verts_count; ++i)
//		{
//			for (int j = 0; j < lemin.verts_count; ++j)
//				printf("% d|", lemin.matrix[i][j]);
//			printf("\n-----------------------\n");
//		}
//		find_solution(&lemin);
//		test(&lemin);
		// main_algo(&lemin);
		// (lemin.beauty & INPUT) ? 0 : print_input(&lemin);
		// (lemin.beauty & PATHS) ? print_paths(&lemin) : 0;
		// go_through_routes(&lemin);
		// (lemin.beauty & RESULT) ? print_result(&lemin) : 0;
		// (lemin.beauty & LEAKS) ? system("leaks -q lem_in") : 0;
	}
	return (0);
}
