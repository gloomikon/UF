
#include "fillit.h"

int	put_piece(t_vector ptn, t_piece tet, char **sqr, char c)
{
	*(*(sqr + ptn.y + tet.coords[0].y) + ptn.x + tet.coords[0].x) = c;
	*(*(sqr + ptn.y + tet.coords[1].y) + ptn.x + tet.coords[1].x) = c;
	*(*(sqr + ptn.y + tet.coords[2].y) + ptn.x + tet.coords[2].x) = c;
	*(*(sqr + ptn.y + tet.coords[3].y) + ptn.x + tet.coords[3].x) = c;
//	ft_putarr(sqr);
	return (1);
}
