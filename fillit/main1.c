
#include "fillit.h"

int	main(void)
{
	int i = 0;
	int j = 0;
	char **a;
	a = (char **)malloc(sizeof(char*) * 5);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*(a + j) = ft_strnew(5);
			ft_memset((char *)*(a + j), (int)('.'), 4);
			j++;
		}
		i++;
	}
	*(a + j) = NULL;
	t_piece t;
	t.q.x = 0;
	t.q.y = 0;
	
	t.w.x = 0;
	t.w.y = 1;

	t.e.x = 0;
	t.e.y = 2;

	t.r.x = 0;
	t.r.y = 3;

	t_vector ptn;
	ptn.x = 1;
	ptn.y = 0;

	printf("fits ?%d\n", piece_fits(ptn, t, a));
	ft_putarr(a);
	printf("\n");
	put_piece(ptn, t, a);
	ft_putarr(a);
}
