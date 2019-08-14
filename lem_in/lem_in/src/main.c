/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 17:57:05 by mzhurba          ###   ########.fr       */
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

void	test(t_lemin *lemin)
{
	for (int i = 0; i < lemin->verts_count; i++)
	{
		printf("%p\n", lemin->verts_arr[i]->next);
	}

	for (int i = 0; i < lemin->verts_count; ++i)
	{
		for (int j = 0; j < lemin->verts_count; ++j)
			ft_printf("%d ", lemin->matrix[i][j]);
		ft_printf("\n");
	}
}

void	add_path(t_paths **path_list, t_queue *path, int len)
{
	t_paths	*new;

	new = (t_paths*)malloc(sizeof(t_paths));
	new->path = path;
	new->len = len;
	new->len0 = len;
	new->next = NULL;
	new->prev = NULL;
	if (*path_list)
	{
		while ((*path_list)->next)
			*path_list = (*path_list)->next;
		(*path_list)->next = new;
		new->prev = *path_list;
	}
	else
		*path_list = new;
}

t_queue	*new_queue(t_vert *start)
{
	t_queue *new;

	new = (t_queue *)malloc(sizeof(t_queue));
	new->top = start;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// void	relax(t_lemin *lemin, t_queue *q, int parent, int child)
// {
// 	if (!lemin->verts_arr[parent]->splitted
// 	|| (colony))
// }

// t_queue	*bfs(t_lemin *lemin, int *len)
// {
// 	t_queue	*q;
// 	int		parent;
// 	int		child;

// 	q = new_queue(lemin->start);
// 	lemin->start->closed = 1;
// 	while (q->top != lemin->end)
// 	{
// 		parent = q->top->number;
// 		child = -1;
// 		while (++child < lemin->verts_count)
// 			(lemin->matrix[parent][child] && !lemin->verts_arr[child]->closed) ?
// 			relax(lemin, q, parent, child) : 0;
// 	}
// }

// void	find_solution(t_lemin *lemin)
// {
// 	t_queue	*path;
// 	t_paths	*path_list;
// 	int		len;

// 	path_list = NULL;
// 	while ((path = bfs(lemin, &len)))
// 		add_path(&path_list, path, len);
// }

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
		//find_solution(&lemin);
		test(&lemin);
		// main_algo(&lemin);
		// (lemin.beauty & INPUT) ? 0 : print_input(&lemin);
		// (lemin.beauty & PATHS) ? print_paths(&lemin) : 0;
		// go_through_routes(&lemin);
		// (lemin.beauty & RESULT) ? print_result(&lemin) : 0;
		// (lemin.beauty & LEAKS) ? system("leaks -q lem_in") : 0;
	}
	return (0);
}
