/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:31:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:31:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	piece_valid(t_piece *tet)
{
	if (tet->coords[0].x == -1 && tet->coords[0].y == -1)
		return (1);
	if (!block_touches(tet->coords[0], *tet) ||
	!block_touches(tet->coords[1], *tet) ||
	!block_touches(tet->coords[2], *tet) ||
	!block_touches(tet->coords[3], *tet))
	{
		tet->coords[0] = create_vector_from_coords(-2, -2);
		return (0);
	}
	if (block_is_edge(tet->coords[0], *tet) +
	block_is_edge(tet->coords[1], *tet) +
	block_is_edge(tet->coords[2], *tet) +
	block_is_edge(tet->coords[3], *tet) > 3)
	{
		tet->coords[0] = create_vector_from_coords(-2, -2);
		return (0);
	}
	return (1);
}
