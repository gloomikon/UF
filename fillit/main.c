#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_set	*pcs;

	if (argc == 1)
		return (printf("usage: ./fillit file_with_tetriminos\n"));
	fd = open(*(argv + 1), O_RDONLY);
	if (!file_valid(fd, &pcs))
	{
		printf("GABELLA!\n");
		return (0);
	}
	while (pcs)
	{
		print_piece(pcs->tet);
		pcs = pcs->next;
	}
	delete_list(&pcs);
}
