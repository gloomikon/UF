/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:44:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/16 19:36:47 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/ft_printf/includes/header.h"

# define PROGRAM_FLAGS	"ircpelh"

# define TRUE	1
# define FALSE	0

# define INPUT	(1 << 0)
# define RESULT	(1 << 1)
# define COLOR	(1 << 2)
# define PATHS	(1 << 3)
# define EMOJI	(1 << 4)
# define LEAKS	(1 << 5)
# define HELP	(1 << 6)

# define START	1
# define MID	2
# define END	3


typedef struct		s_vert
{
	char			*name;
	int 			len;
	int 			number;
	int				x;
	int				y;
	int				type;
	struct s_vert	*parent;
	struct s_vert	*next;
	bool			visited;
}					t_vert;

typedef struct		s_path
{
	t_vert			*vert;
	t_vert			*prev;
}					t_path;

typedef struct		s_string
{
	char			*str;
	struct s_string	*next;
}					t_string;

typedef struct		s_queue
{
	t_vert			*top;
	struct s_queue	*next;
	struct s_queue	*prev;
}					t_queue;

typedef struct		s_paths
{
	t_queue			*path;
	int				len;
	int				len0;
	struct s_paths	*next;
	struct s_paths	*prev;
}					t_paths;

typedef struct		s_lemin
{
	long long		ants_begin;
	int				verts_count;
	u_int8_t		beauty;
	int				edges;
	t_vert			**verts_arr;
	t_vert			*verts;
	int				**matrix;
	t_vert			*start;
	t_vert			*end;
	t_string		*strs;
	int				result;
	t_paths			paths;
}					t_lemin;


/*
** READING
*/

void				read_data(t_lemin *lemin);
void				read_ants(t_lemin *lemin);
void				read_vertices(t_lemin *lemin, char **line);
void				read_edges(t_lemin *lemin, char **line);

/*
** SAVING INPUT
*/

t_string			*create_string(char *line);
void				strs_push_str(t_string **strs, t_string *str);
char				*read_line(t_lemin *lemin);

/*
** LISTS' FUNCTIONS
*/

void				add_vert_to_lst(t_lemin *lemin, t_vert *vert);
t_vert				*create_vert(char *str, int type, int number);
void				add_edge(t_lemin *lemin, t_vert *a, t_vert *b);

/*
** QUEUE'S FUNCTIONS
*/

t_queue				*new_queue(t_vert *start);
void				queue_push(t_queue **q, t_vert *vert);
void				queue_pop(t_queue **q);
void				queue_push_front(t_queue **q, t_vert *vert);

/*
** VALIDATION
*/

int					command(char *str);
int					comment(char *str);
int					room(char *str);
void				check_vert(t_lemin *lemin, t_vert *vert);
void				check_edge(t_lemin *lemin, char **str, t_vert **a, t_vert **b);

/*
** PATH FUNCS
*/

t_queue				*create_path(t_lemin *lemin, int *len);
void				add_path(t_paths **path_list, t_queue *path, int len);

/*
** ALGORITHM
*/

void	find_solution(t_lemin *lemin);
t_queue	*bfs(t_lemin *lemin, int *len);
void	relax(t_lemin *lemin, t_queue *q, int parent, int child);


/*
** DISPLAYING RESULT
*/

// void				print_input(t_lemin *lemin);
// void				print_paths(t_lemin *lemin);
// void				print_result(t_lemin *lemin);
void				print_help(void);
void	print_paths(t_paths *path_list);

/*
** AUXILIARY
*/

void				err_exit(int leaks, char *error);
t_vert				*find_vert(t_lemin *lemin, char *line);
void				create_matrix(t_lemin *lemin);
void				update_info(t_lemin *lemin);

#endif
