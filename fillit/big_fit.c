
#include "fillit.h"

char	**big_fit(int size, t_set *pcs)
{
	char		**sqr;
	t_vector	ptn;
	int		j;

	sqr = initialize_square(size); 
	ptn.x = 0;
	ptn.y = 0;
	if (!fit(ptn, pcs, sqr, 0))
	{
		j = 0;
		while (j < size)
		{
			free(*(sqr + j));
			j++;
		}
		free(sqr);
		return(big_fit(size + 1, pcs));
	}
	return (sqr);
}
