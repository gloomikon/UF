/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_from_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:28:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:28:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	vector_from_piece(t_vector c, t_vector *first_point,
		int *points, t_piece *curr)
{
	t_vector	coords;

	if (!(++(*points)))
	{
		*first_point = create_vector_from_coords(c.x, c.y);
		coords = create_vector_from_coords(0, 0);
	}
	else if (*points < 4)
		coords = create_vector_from_coords(c.x - first_point->x,
				c.y - first_point->y);
	if (*points < 4)
		curr->coords[*points] = coords;
	else
		curr->coords[0] = create_vector_from_coords(-2, -2);
}
