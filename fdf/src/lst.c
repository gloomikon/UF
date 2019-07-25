/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:41:50 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/25 03:36:39 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		lst_push(t_point_lst **lst, t_point_lst *new)
{
	if (lst)
	{
		if (new)
			new->nxt = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

t_point_lst	*lst_pop(t_point_lst **lst)
{
	t_point_lst *top;

	top = NULL;
	if (lst && *lst)
	{
		top = *lst;
		*lst = (*lst)->nxt;
	}
	return (top);
}


t_point_lst	*new_point(char *s, t_fdf *fdf)
{
	t_point_lst	*coord;
	char		**parts;

	coord = (t_point_lst *)ft_memalloc(sizeof(t_point_lst));
	parts = ft_strsplit(s, ',');
	if (!ft_isnumber(parts[0], 10))
		err_exit(ERR_MAP);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		err_exit(ERR_MAP);
	coord->val.z = ft_atoi(parts[0]);
	coord->val.color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	fdf->color.has_color = parts[1] ? 1 : fdf->color.has_color;
	coord->nxt = NULL;
	free_split_array(parts);
	return (coord);
}
