/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:14:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:25:45 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define GNL get_next_line
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# define MALLCHECK(x) if (!x) return (NULL)

typedef struct	s_vector
{
	int x;
	int y;
}				t_vector;

typedef struct	s_piece
{
	t_vector coords[4];
}				t_piece;

typedef	struct	s_set
{
	t_piece			tet;
	struct s_set	*next;
	struct s_set	*prev;
}				t_set;

typedef struct	s_fit_argument
{
	int		*fill;
	int		chain;
	char	**square;
}				t_fit_argument;

int				put_piece(t_vector position, t_piece tetrimino,
					char **square, char fill);
int				file_valid(int fd, t_set **lst);
int				fit(t_vector *position, t_set **pieces, t_fit_argument arg);
t_vector		free_slot(t_vector position, char **square);
t_vector		next_legal_slot(t_vector position, t_piece tetrimino,
					char **square);
t_set			*create_list(int fd);
t_vector		erase_piece(char filling, t_piece tetrimino, char **square);
char			**big_fit(int size, t_set *pieces);
char			**initialize_square(int size);
t_vector		create_vector_from_coords(int x, int y);
void			free_square(char **sqr);
int				square_root(int n);
int				count_pieces(t_set *pieces);
int				int_putstr(char *s, int fd);
int				vectors_equall(t_vector a, t_vector b);
int				block_belongs(t_vector block, t_piece tet);
int				block_touches(t_vector block, t_piece tet);
int				block_is_edge(t_vector block, t_piece tet);
int				piece_valid(t_piece *tet);
int				check_full_line(char *str, t_piece *piece);
void			check_empty_line(char **line, t_piece *piece);
void			vector_from_piece(t_vector c, t_vector *first_point,
					int *points, t_piece *curr);
void			full_line_action(t_vector *iters, char *line,
				int *points, t_piece *curr);
t_piece			*invalid_piece(t_piece *curr, char **line);
int				end_action(int ret, int *x);
t_piece			read_piece(int fd);
void			delete_list(t_set **head);
t_set			*create_node(t_set *prev);
t_set			*clear_and_return(t_set **head);
t_set			*final_action(t_set **head, t_set **iter);
t_set			*create_list(int fd);
int				check_endl(int fd);

#endif
