/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/16 20:06:46 by mzhurba          ###   ########.fr       */
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

void	dejkstra(t_lemin *lemin)
{
	int i;
	int min;
	t_vert	*vert;

	lemin->start->len = 0;
	i = 0;
	while (++i < lemin->verts_count)
	{
		printf("%d  %s\n", lemin->verts_arr[i]->visited, lemin->verts_arr[i]->name);
		lemin->verts_arr[i]->len = INT_MAX;
	}
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
	vert = lemin->end;
	while (vert)
	{
		printf("%s%s", vert->name, vert->parent ? "->" : "\n");
		vert = vert->parent;
	}
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
