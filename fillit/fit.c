
#include "fillit.h"

int	fit(t_vector ptn, t_list *pcs, char **sqr)
{
	if (piece_fits(ptn, pcs->tet, sqr))
		put_piece(ptn, pcs->tet, sqr);
