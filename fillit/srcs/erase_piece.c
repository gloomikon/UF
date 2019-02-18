/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:29:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:12:28 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_vector	locate_piece(char fill, char **sqr)
{
	t_vector	ret;
	int			size;

	size = ft_strlen(*sqr);
	ret.x = 0;
	ret.y = 0;
	while (ret.y < size)
	{
		ret.x = 0;
		while (ret.x < size)
		{
			if (*(*(sqr + ret.y) + ret.x) == fill)
				return (ret);
			ret.x++;
		}
		ret.y++;
	}
	ret.x = -1;
	return (ret);
}

t_vector	erase_piece(char fill, t_piece tet, char **sqr)
{
	t_vector ptn;

	ptn = locate_piece(fill, sqr);
	*(*(sqr + ptn.y + tet.coords[0].y) + ptn.x + tet.coords[0].x) = '.';
	*(*(sqr + ptn.y + tet.coords[1].y) + ptn.x + tet.coords[1].x) = '.';
	*(*(sqr + ptn.y + tet.coords[2].y) + ptn.x + tet.coords[2].x) = '.';
	*(*(sqr + ptn.y + tet.coords[3].y) + ptn.x + tet.coords[3].x) = '.';
	if (*(*(sqr + ptn.y) + ptn.x + 1) == '\0')
	{
		ptn.y++;
		ptn.x = 0;
	}
	else
		ptn.x++;
	return (ptn);
}
