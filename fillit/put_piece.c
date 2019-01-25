
#include "fillit.h"

int	put_piece(t_vector ptn, t_piece tet, char **sqr, char c)
{
	if (!piece_fits(ptn, tet, sqr))
		return (0);
	*(*(sqr + ptn.y + tet.q.y) + ptn.x + tet.q.x) = c;
	*(*(sqr + ptn.y + tet.w.y) + ptn.x + tet.w.x) = c;
	*(*(sqr + ptn.y + tet.e.y) + ptn.x + tet.e.x) = c;
	*(*(sqr + ptn.y + tet.r.y) + ptn.x + tet.r.x) = c;
	return (1);
}
