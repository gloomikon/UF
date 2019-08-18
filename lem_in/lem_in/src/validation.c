/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:21:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 17:04:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		command(char *str)
{
	if (!ft_strncmp(str, "##", 2))
	{
		if (!ft_strcmp(str, "##start"))
			return (START);
		else if (!ft_strcmp(str, "##end"))
			return (END);
		else
			return (MID);
	}
	return (0);
}

int		comment(char *str)
{
	if (!command(str) && !ft_strncmp(str, "#", 1))
		return (1);
	return (0);
}

int		room(char *str)
{
	int		result;
	char	**split;

	result = 0;
	split = ft_strsplit(str, ' ');
	if (ft_strsplit_len(split) == 3
		&& split[0][0] != 'L'
		&& split[0][0] != '#'
		&& ft_isnumber(split[1], 10)
		&& ft_isnumber(split[2], 10))
		result = 1;
	ft_free_split_array(split);
	return (result);
}

bool	check_vert(t_vert *verts, t_vert *vert)
{
	while (verts)
	{
		if (vert != verts
			&& (!ft_strcmp(vert->name, verts->name)
				|| (vert->x == verts->x && vert->y == verts->y)))
			return (false);
		verts = verts->next;
	}
	return (true);
}
