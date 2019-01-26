#ifndef _FILLIT_H_
# define _FILLIT_H_
#include "libft/includes/libft.h"
#include <stdio.h>
typedef struct s_vector
{
	int x;
	int y;
}		t_vector;

typedef struct s_piece
{
	t_vector coords[4];
}		t_piece;

typedef	struct s_dlist
{
	t_piece tet;
	struct s_dlist *next;
	struct s_dlist *prev;
}				t_dlist;

t_piece ft_read_piece(int fd);
t_dlist *ft_create_list(int fd);
void ft_print_piece(t_piece piece);
//int	piece_fits(t_vector position, t_piece tetrimino, char **square);
//int	put_piece(t_vector position, t_piece tetrimino, char **square);
//int	fit(t_vector position, t_piece tetrimino, char **square);
//int	next_slot(t_vector position, char **square);

#endif
