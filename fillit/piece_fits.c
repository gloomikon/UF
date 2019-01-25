
#include "fillit.h"

int	piece_fits(t_vector ptn, t_piece tet, char **sqr)
{
	int size;

	size = ft_strlen(*sqr);
	printf("size is %d\n", size);
/*	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", ptn.y + (tet.q).y < 0, ptn.y + (tet.q).y > size, ptn.x + (tet.q).x < 0, ptn.x + (tet.q).x > size, ptn.y + (tet.w).y < 0, ptn.y + (tet.w).y > size, ptn.x + (tet.w).x < 0, ptn.x + (tet.w).x > size, ptn.y + (tet.e).y < 0, ptn.y + (tet.e).y > size, ptn.x + (tet.e).x < 0, ptn.x + (tet.e).x > size,  ptn.y + (tet.r).y < 0, ptn.y + (tet.r).y > size, ptn.x + (tet.r).x < 0, ptn.x + (tet.r).x > size, *(*(sqr + ptn.y + (tet.q).y)) + ptn.x + ((tet.q).x) == '.', *(*(sqr + ptn.y + (tet.w).y)) + ptn.x + ((tet.w).x) == '.', *(*(sqr + ptn.y + (tet.e).y)) + ptn.x + ((tet.e).x) == '.', *(*(sqr + ptn.y + (tet.r).y)) + ptn.x + ((tet.r).x) == '.');*/
	if (ptn.y + (tet.q).y < 0 || ptn.y + (tet.q).y > size
	|| ptn.x + (tet.q).x < 0 || ptn.x + (tet.q).x > size
	|| ptn.y + (tet.w).y < 0 || ptn.y + (tet.w).y > size
	|| ptn.x + (tet.w).x < 0 || ptn.x + (tet.w).x > size
	|| ptn.y + (tet.e).y < 0 || ptn.y + (tet.e).y > size
	|| ptn.x + (tet.e).x < 0 || ptn.x + (tet.e).x > size
	|| ptn.y + (tet.r).y < 0 || ptn.y + (tet.r).y > size
	|| ptn.x + (tet.r).x < 0 || ptn.x + (tet.r).x > size)
		return (0);
	return (*(*(sqr + ptn.y + (tet.q).y) + ptn.x + ((tet.q).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.w).y) + ptn.x + ((tet.w).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.e).y) + ptn.x + ((tet.e).x)) == '.' &&
		*(*(sqr + ptn.y + (tet.r).y) + ptn.x + ((tet.r).x))== '.');
}
