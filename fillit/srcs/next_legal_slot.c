/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_legal_slot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:30:39 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:14:51 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			piece_fits(t_vector ptn, t_piece tet, char **sqr)
{
	int size;

	size = ft_strlen(*sqr) - 1;
	if (ptn.y + (tet.coords[0]).y < 0 || ptn.y + (tet.coords[0]).y > size
	|| ptn.x + (tet.coords[0]).x < 0 || ptn.x + tet.coords[0].x > size
	|| ptn.y + (tet.coords[1]).y < 0 || ptn.y + (tet.coords[1]).y > size
	|| ptn.x + (tet.coords[1]).x < 0 || ptn.x + (tet.coords[1]).x > size
	|| ptn.y + (tet.coords[2]).y < 0 || ptn.y + (tet.coords[2]).y > size
	|| ptn.x + (tet.coords[2]).x < 0 || ptn.x + (tet.coords[2]).x > size
	|| ptn.y + (tet.coords[3]).y < 0 || ptn.y + (tet.coords[3]).y > size
	|| ptn.x + (tet.coords[3]).x < 0 || ptn.x + (tet.coords[3]).x > size)
		return (0);
	return (*(*(sqr + ptn.y + (tet.coords[0]).y) +
			ptn.x + ((tet.coords[0]).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.coords[1]).y) + ptn.x +
			((tet.coords[1]).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.coords[2]).y) + ptn.x +
			((tet.coords[2]).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.coords[3]).y) + ptn.x +
			((tet.coords[3]).x)) == '.');
}

t_vector	next_legal_slot(t_vector ptn, t_piece tet, char **sqr)
{
	t_vector	ret;
	int			size;

	if (!*(sqr + ptn.y))
	{
		ptn.x = -1;
		return (ptn);
	}
	size = ft_strlen(*sqr);
	ret.x = ptn.x;
	ret.y = ptn.y;
	while (ret.y < size)
	{
		if (ret.y > ptn.y)
			ret.x = 0;
		while (ret.x < size)
		{
			if (piece_fits(ret, tet, sqr) && *(*(sqr + ret.y) + ret.x) == '.')
				return (ret);
			ret.x++;
		}
		ret.y++;
	}
	ret.x = -1;
	return (ret);
}
