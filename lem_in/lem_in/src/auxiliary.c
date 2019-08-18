/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/18 19:30:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		err_exit(int leaks, char *error)
{
	leaks ? system("leaks -q a.out") : 0;
	ft_printf("{red}ERROR: %s\n{off}", error);
	exit(1);
	return (1);
}

t_vert	*find_vert(t_lemin *lemin, char *line)
{
	int	i;

	i = -1;
	while (++i < lemin->verts_count)
		if (!ft_strcmp(lemin->verts[i]->name, line))
		{
			ft_strdel(&line);
			return (lemin->verts[i]);
		}
	ft_strdel(&line);
	return (NULL);
}

int		free_verts_list(t_vert **verts)
{
	t_vert	*curr;
	t_vert	*next;

	curr = *verts;
	while (curr)
	{
		next = curr->next;
		free(curr->name);
		free(curr);
		curr = next;
	}
	return (1);
}

int		**create_matrix(t_lemin *lemin)
{
	int	**matrix;
	int	i;

	i = -1;
	if (!(matrix = (int**)malloc(sizeof(int*) * lemin->verts_count)))
		err_exit(lemin->beauty & LEAKS, "Memory error");
	while (++i < lemin->verts_count)
		if (!(matrix[i] = (int*)ft_memalloc(sizeof(int) * lemin->verts_count)))
			err_exit(lemin->beauty & LEAKS, "Memory error");
	return (matrix);
}

void	create_adjacency_matrix(t_lemin *lemin, t_vert *verts)
{
	int	i;

	lemin->matrix = create_matrix(lemin);
	lemin->verts = (t_vert**)malloc(sizeof(t_vert*) * lemin->verts_count);
	i = 0;
	while (verts)
	{
		lemin->verts[i] = verts;
		verts = verts->next;
		lemin->verts[i]->next = NULL;
		(++i);
	}
}

//void	update_info(t_lemin *lemin)
//{
//	int	i;
//
//	i = -1;
//	while (++i < lemin->verts_count)
//	{
//		lemin->verts_arr[i]->closed = 0;
//		lemin->verts_arr[i]->next = NULL;
//	}
//}
