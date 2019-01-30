
#include "fillit.h"

int	vectors_equall(t_vector a, t_vector b)
{
	return (a.x == b.x && a.y == b.y);
}

int	block_belongs(t_vector block, t_piece tet)
{
	return (vectors_equall(block, tet.coords[0]) || vectors_equall(block, tet.coords[1])
	|| vectors_equall(block, tet.coords[2]) || vectors_equall(block, tet.coords[3]));
}

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
	left.x = block.x -1;
	left.y = block.y;
	right.x = block.x + 1;
	right.y = block.y;
	return (block_belongs(up, tet) + block_belongs(down, tet)
	+ block_belongs(left, tet) + block_belongs(right, tet));
}

int	block_is_edge(t_vector block, t_piece tet)
{
	if (block_touches(block, tet) == 1)
		return (1);
	return (0);
}

int	piece_valid(t_piece tet)
{
	if (!block_touches(tet.coords[0], tet) || !block_touches(tet.coords[1], tet)
	|| !block_touches(tet.coords[2], tet) || !block_touches(tet.coords[3], tet))
		return (0);
	if (block_is_edge(tet.coords[0], tet) + block_is_edge(tet.coords[1], tet) +
	block_is_edge(tet.coords[2], tet) + block_is_edge(tet.coords[3], tet) > 3)
		return (0);
	return (1);
}
