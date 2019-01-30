
#ifndef _FILLIT_H_
# define _FILLIT_H_
# define gnl get_next_line
#include "libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_vector
{
	int x;
	int y;
}		t_vector;

typedef struct s_piece
{
	t_vector coords[4];
}		t_piece;

typedef	struct		s_set
{
	t_piece 	tet;
	struct s_set 	*next;
	struct s_set 	*prev;
}			t_set;

int		put_piece(t_vector position, t_piece tetrimino, char **square, char fill);
void print_piece(t_piece piece);
void delete_list(t_set **head);
int         file_valid(int fd, t_set **lst);
int		fit(t_vector position, t_set *pieces, char **square, int filling);
t_vector	free_slot(t_vector position, char **square);
t_vector	next_legal_slot(t_vector position, t_piece tetrimino, char **square);
t_set		*create_list(int fd);
t_vector	erase_piece(char filling, t_piece tetrimino, char **square);
char		**big_fit(int size, t_set *pieces);
char		**initialize_square(int size);

#endif
