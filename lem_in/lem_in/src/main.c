/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/19 20:06:26 by mzhurba          ###   ########.fr       */
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


int		count_result(int ants, t_comb *comb)
{
	int	path;
	int	sum_of_paths;

	if (comb->count == 0)
		return (INT_MAX);
	path = -1;
	sum_of_paths = 0;
	while (++path < comb->count)
		if (comb->paths_arr[path]->len == 1)
			return (1);
		else
			sum_of_paths += comb->paths_arr[path]->len;
	return ((ants + sum_of_paths - 1) / path);
}

int		annul(t_lemin *lemin)
{
	int	i;

	i = -1;
	while (++i < lemin->verts_count)
		!(lemin->verts[i]->len = INT_MAX)
		&& !(lemin->verts[i]->used = false)
		&& (lemin->verts[i]->parent = NULL);
	return (1);
}

void	init_path(t_comb *comb, int verts)
{
	comb->paths_arr[comb->count] = (t_path*)malloc(sizeof(t_path));
	comb->paths_arr[comb->count]->len = 0;
	if (!(comb->paths_arr[comb->count]->verts_arr =
			(t_vert**)ft_memalloc(sizeof(t_vert*) * verts)))
		err_exit(true, "MEMORY ERROR");
}

int		add_path(t_lemin *lemin, t_comb *comb)
{
	int		len;
	t_vert	*tmp;

	init_path(comb, lemin->verts_count);
	len = 0;
	tmp = lemin->end;
	while (tmp && ++len)
		tmp = tmp->parent;
	comb->paths_arr[comb->count]->len = len - 1;
	tmp = lemin->end;
	while (tmp
		&& (comb->paths_arr[comb->count]->verts_arr[--len] = tmp))
		tmp = tmp->parent;
	comb->count += 1;
	comb->result = count_result(lemin->ants, comb);
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

int		free_combination(t_comb **combination)
{
	int	paths;

	paths = -1;
	while (++paths < (*combination)->count)
	{
		free((*combination)->paths_arr[paths]->verts_arr);
		free((*combination)->paths_arr[paths]);
	}
	free((*combination)->paths_arr);
	free(*combination);
	return (1);
}

void	dijkstra(t_lemin *lemin)
{
	int i;
	int min;
	t_vert	*vert;

	lemin->start->len = 0;
	while ((i = -1) && (min = INT_MAX) && !(vert = NULL))
	{
		while (++i < lemin->verts_count)
			if (!lemin->verts[i]->visited
				&& lemin->verts[i]->len < min
				&& (vert = lemin->verts[i]))
				min = lemin->verts[i]->len;
		if (!vert)
			break;
		i = -1;
		while (++i < lemin->verts_count)
			(lemin->matrix[vert->number][i]
			&& lemin->verts[i]->len > vert->len + 1
			&& (lemin->verts[i]->len = vert->len + 1)
			&& (lemin->verts[i]->parent = vert));
		(vert->visited = true);
	}
	if (!lemin->end->parent)
		err_exit(lemin->beauty & LEAKS, "No path!");
}

int		bellman_ford(t_lemin *lemin, t_comb *tmp)
{
	int		stop;
	int		i;
	int		j;
	bool	relax;

	lemin->start->len = 0;
	stop = -1;
	while (++stop < lemin->verts_count && (i = -1) && !(relax = false))
	{
		while (++i < lemin->verts_count && (j = -1))
			while (++j < lemin->verts_count)
				if (lemin->matrix[i][j]
				&& lemin->verts[i]->len != INT_MAX
				&& lemin->verts[i]->len + lemin->matrix[i][j] < lemin->verts[j]->len
				&& (lemin->verts[j]->parent = lemin->verts[i])
				&& (relax = true))
					lemin->verts[j]->len = lemin->verts[i]->len + lemin->matrix[i][j];
		if (!relax)
			break;
	}
	if (!lemin->end->parent)
		return (0);
	return (add_path(lemin, tmp));
}

int		update_graph(t_lemin *lemin)
{
	t_vert	*tmp;

	tmp = lemin->end;
	while (tmp->parent)
	{
		if (lemin->matrix[tmp->number][tmp->parent->number] == 1)
			lemin->matrix[tmp->number][tmp->parent->number] = -1;
		if (lemin->matrix[tmp->parent->number][tmp->number] == 1)
			lemin->matrix[tmp->parent->number][tmp->number] = 0;
		tmp = tmp->parent;
	}
	return (1);
}

void	sort_paths(t_comb *comb)
{
	int	i;
	int	j;
	int	min;
	t_path	*tmp;

	i = -1;
	while (++i < comb->count)
	{
		min = i;
		j = i;
		while (++j < comb->count)
			if (comb->paths_arr[j]->len < comb->paths_arr[min]->len)
				min = j;
		if (min != i)
		{
			tmp = comb->paths_arr[i];
			comb->paths_arr[i] = comb->paths_arr[min];
			comb->paths_arr[min] = tmp;
		}
	}
}

void	delete_one_path(t_comb *comb, int path, int vert)
{
	int	i;

	i = 0;
	while (++i < vert)
		comb->paths_arr[path]->verts_arr[i]->used = false;
	free(comb->paths_arr[path]->verts_arr);
	free(comb->paths_arr[path]);
	i = path;
	while (++i < comb->count)
		comb->paths_arr[i - 1] = comb->paths_arr[i];
	comb->count -= 1;
}

void	delete_joint_paths(t_comb *comb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < comb->count && !(j = 0))
		while (++j < comb->paths_arr[i]->len - 1)
			if (comb->paths_arr[i]->verts_arr[i]->used)
			{
				delete_one_path(comb, i, j);
				break;
			}
			else
				comb->paths_arr[i]->verts_arr[j]->used = true;
}

void	print_comb(t_comb *comb, char *message)
{
	ft_printf("{yellow}%s   PATH_COUNT = %d\n{off}", message, comb->count);
	for (int i = 0; i < comb->count; ++i)
	{
		printf("path len = %d\n", comb->paths_arr[i]->len);
		for (int j = 0; j <= comb->paths_arr[i]->len; ++j)
			ft_printf("%s%s",
					  comb->paths_arr[i]->verts_arr[j]->name,
					  j == comb->paths_arr[i]->len ? "\n\n" : "->");
	}
	if (ft_strequ(message, "new") || ft_strequ(message, "best"))
		ft_printf("{green}RESULT = %d\n{off}", comb->result);
	printf("\n\n");
}

void	create_new_combination(t_comb *new, t_comb *tmp, t_lemin *lemin, int **matrix)
{
	int i;
	int j;
	int	old;

	i = -1;
	while (++i < tmp->count && (j = -1))
		while (++j < tmp->paths_arr[i]->len)
			matrix[tmp->paths_arr[i]->verts_arr[j]->number]
			[tmp->paths_arr[i]->verts_arr[j + 1]->number] = 1;
	i = -1;
	while (++i < lemin->verts_count && (j = -1))
		while (++j < lemin->verts_count)
			(matrix[i][j]) && (matrix[j][i]) && !(matrix[i][j] = 0)
			&& (matrix[j][i] = 0);
	old = -1;
	while (new->count != tmp->count)
	{
		init_path(new, lemin->verts_count);
		i = lemin->start->number;
		j = old;
		while (i != lemin->end->number)
		{
			++j;
			if (j == lemin->verts_count)
			{
				free(new->paths_arr[new->count]->verts_arr);
				free(new->paths_arr[new->count]);
				break;
			}
			else if ((matrix[i][j])
			&& (new->paths_arr[new->count]->
			verts_arr[new->paths_arr[new->count]->len++] = lemin->verts[i]))
			{
				(i == lemin->start->number) && (old = j);
				i = j;
				j = -1;
			}
		}
		if (j != lemin->verts_count)
		{
			new->paths_arr[new->count]->
					verts_arr[new->paths_arr[new->count]->len] = lemin->verts[i];
			new->count += 1;
		}
		if (j == lemin->verts_count && i == lemin->start->number)
			break;
	}
	sort_paths(new);
	delete_joint_paths(new);
	new->result = count_result(lemin->ants, new);
}

void	anull_matrix(int **matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = -1))
		while (++j < size)
			matrix[i][j] = 0;
}

void	free_matrix(int ***matrix, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free((*matrix)[i]);
	free(*matrix);
}

void	bhandari(t_lemin *lemin)
{
	t_comb	*new_comb;
	t_comb	*tmp_comb;
	int		**matrix;

	matrix = create_matrix(lemin);
	tmp_comb = init_combination(lemin->max_paths);
	add_path(lemin, tmp_comb);
	while (tmp_comb->count < lemin->max_paths
	&& update_graph(lemin) && annul(lemin) && (bellman_ford(lemin, tmp_comb)))
	{
//		print_comb(tmp_comb, "tmp");
		new_comb = init_combination(lemin->max_paths);
		create_new_combination(new_comb, tmp_comb, lemin, matrix);
//		print_comb(new_comb, "new");
		if ((lemin->combination->result > new_comb->result)
		&& (free_combination(&lemin->combination)))
			lemin->combination = new_comb;
		else
			free_combination(&new_comb);
		anull_matrix(matrix, lemin->verts_count);
	}
	free_matrix(&matrix, lemin->verts_count);
	free_combination(&tmp_comb);
}

//static void	generate_one_turn(long long *i, t_lemin *lemin)
//{
//	int		r;
//	t_edge	*tmp;
//
//	lemin->result += 1;
//	while (++(*i) < lemin->ants_begin)
//		if (lemin->ants[*i] == lemin->start
//			&& (r = find_free_route(lemin)) != -1
//			&& lemin->ants_left > count_sum_of_routes(lemin, r))
//		{
//			lemin->ants[*i] = lemin->routes[r].start->end;
//			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
//			ft_printf("%d-%s ", *i + 1, lemin->ants[*i]->name);
//			lemin->ants[*i]->ant_number += 1;
//			lemin->ants_left -= 1;
//		}
//		else if (lemin->ants[*i] != lemin->start
//				 && lemin->ants[*i] != lemin->end)
//		{
//			lemin->ants[*i]->ant_number -= 1;
//			tmp = lookfor_edge(lemin, lemin->ants[*i], START);
//			lemin->ants[*i] = tmp->end;
//			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
//			ft_printf("%d-%s ", *i + 1, lemin->ants[*i]->name);
//			lemin->ants[*i]->ant_number += 1;
//		}
//}

int		count_sum_of_paths(t_lemin *lemin, int n)
{
	int	i;
	int	sum;

	if (n == 0)
		return (0);
	i = -1;
	sum = 0;
	while (++i < n)
		sum += (lemin->combination->paths_arr[n]->len -
				lemin->combination->paths_arr[i]->len);

	return (sum);
}

int		find_free_path(t_lemin *lemin)
{
	int	i;
	i = -1;
	while (++i < lemin->combination->count)
		if (lemin->combination->paths_arr[i]->verts_arr[1] == lemin->end
		|| lemin->combination->paths_arr[i]->verts_arr[1]->ants == 0)
		return (i);
	return (-1);
}

void	generate_one_turn(int **ants, int *ants_left, t_lemin *lemin)
{
	int		r;
	int		i;

	lemin->result += 1;
	i = -1;
	while (++i < lemin->ants)
		if (ants[i][0] == -1
		&& ((r = find_free_path(lemin)) != -1)
		&& ((*ants_left) > count_sum_of_paths(lemin, r)))
		{
			ants[i][0] = r;
			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
			ft_printf("%d-%s ", i + 1,
			lemin->combination->paths_arr[r]->verts_arr[(++ants[i][1])]->name);
			++(lemin->combination->paths_arr[r]->verts_arr[ants[i][1]]->ants);
			--(*ants_left);
		}
		else if (ants[i][0] != -1
		&& lemin->combination->paths_arr[ants[i][0]]->verts_arr[ants[i][1]] !=
													lemin->end)
		{
			--(lemin->combination->paths_arr[ants[i][0]]->verts_arr[ants[i][1]]->ants);
			lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
			ft_printf("%d-%s ", i + 1,
					  lemin->combination->paths_arr[r]->verts_arr[(++ants[i][1])]->name);
			++(lemin->combination->paths_arr[r]->verts_arr[ants[i][1]]->ants);
		}
}

void		go_through_routes(t_lemin *lemin)
{
	int		i;
	int		**ants;
	int		ants_left;

	ants_left = lemin->ants;
	ants = (int**)ft_memalloc(sizeof(int*) * lemin->ants);
	i = -1;
	while (++i < lemin->ants)
		(ants[i] = (int*)ft_memalloc(sizeof(int) * 2))
		&& (ants[i][0] = -1);
	while (lemin->end->ants != lemin->ants)
	{
		generate_one_turn(ants, &ants_left, lemin);
		ft_printf("\n");
	}
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
		dijkstra(&lemin);
		count_max_paths(&lemin);
		ft_printf("max = %d verts = %d\n", lemin.max_paths, lemin.verts_count);
		lemin.combination = init_combination(lemin.max_paths);
		add_path(&lemin, lemin.combination);
		bhandari(&lemin);
		print_comb(lemin.combination, "best");
		go_through_routes(&lemin);
		// (lemin.beauty & INPUT) ? 0 : print_input(&lemin);
		// (lemin.beauty & PATHS) ? print_paths(&lemin) : 0;
		// go_through_routes(&lemin);
		// (lemin.beauty & RESULT) ? print_result(&lemin) : 0;
		(lemin.beauty & LEAKS) ? system("leaks -q a.out") : 0;
	}
	return (0);
}
