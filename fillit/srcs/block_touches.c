/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_touches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:48:28 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:48:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	block_touches(t_vector block, t_piece tet)
{
	t_vector up;
	t_vector down;
	t_vector left;
	t_vector right;

	up.x = block.x;
	up.y = block.y - 1;
	down.x = block.x;
	down.y = block.y + 1;
	left.x = block.x - 1;
	left.y = block.y;
	right.x = block.x + 1;
	right.y = block.y;
	return (block_belongs(up, tet) + block_belongs(down, tet)
	+ block_belongs(left, tet) + block_belongs(right, tet));
}
