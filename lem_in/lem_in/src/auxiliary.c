/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/15 15:44:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit(int leaks, char *error)
{
	leaks ? system("leaks -q lem_in") : 0;
	ft_printf("ERROR: %s\n", error);
	exit(1);
}

t_vert	*find_vert(t_lemin *lemin, char *line)
{
	int	i;

	i = -1;
	while (++i < lemin->verts_count)
		if (!ft_strcmp(lemin->verts_arr[i]->name, line))
		{
			ft_strdel(&line);
			return (lemin->verts_arr[i]);
		}
	ft_strdel(&line);
	return (NULL);
}

void	create_matrix(t_lemin *lemin)
{
	int	i;

	i = -1;
	lemin->matrix = (int**)malloc(sizeof(int*) * lemin->verts_count);
	while (++i < lemin->verts_count)
		lemin->matrix[i] = (int*)ft_memalloc(sizeof(int) * lemin->verts_count);
	lemin->verts_arr = (t_vert**)malloc(sizeof(t_vert*) * lemin->verts_count);
	i = 0;
	while (lemin->verts)
	{
		lemin->verts_arr[i] = lemin->verts;
		lemin->verts = lemin->verts->next;
		lemin->verts_arr[i]->next = NULL;
		++i;
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
