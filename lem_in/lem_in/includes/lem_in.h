/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:44:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 17:04:00 by mzhurba          ###   ########.fr       */
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

typedef	struct s_edge	t_edge;

typedef struct		s_vert
{
	char			*name;
	int				x;
	int				y;
	int				type;
	int				bfs_lvl;
	int				number;
	struct s_vert	*next;
}					t_vert;

struct				s_edge
{
	t_vert			*vert;
	struct s_edge	*next;
};

typedef struct		s_route
{
	int				len;
	t_edge			*start;
}					t_route;

typedef struct		s_string
{
	char			*str;
	struct s_string	*next;
}					t_string;

typedef struct		s_lemin
{
	u_int8_t		beauty;
	t_vert			*verts;
	int				**matrix;
	t_vert			*start;
	t_vert			*end;
	int				edges;
	t_string		*strs;
	long long		ants_begin;
	int				result;
	int				verts_count;
}					t_lemin;

void				main_algo(t_lemin *lemin);

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
t_vert	*create_vert(char *str, int type, int number);
// void	add_edge_to_lst(t_vert **a, t_vert **b);
t_edge	*create_edge(t_vert	*vert);
void	add_edge(t_lemin *lemin, t_vert *a, t_vert *b);

/*
** QUEUE'S FUNCTIONS
*/

// t_queue				*queue_create_elem(t_vert *vert);
// void				queue_push_elem(t_queue **queue, t_queue *elem);
// t_queue				*queue_get_curr_elem(t_queue **queue);
// void				queue_update(t_queue **queue, t_vert *vert, t_edge *edges);

/*
** VALIDATION
*/

int					command(char *str);
int					comment(char *str);
int					room(char *str);
void				check_vert(t_lemin *lemin, t_vert *vert);
void	check_edge(t_lemin *lemin, char **str, t_vert **a, t_vert **b);
void	check_duplicate_edge(t_lemin *lemin, t_vert *a, t_vert *b);


/*
** DISPLAYING RESULT
*/

// void				print_input(t_lemin *lemin);
// void				print_paths(t_lemin *lemin);
// void				print_result(t_lemin *lemin);
void				print_help(void);

/*
** AUXILIARY
*/

void	err_exit(int leaks, char *error);
t_vert				*find_vert(t_lemin *lemin, char *line);

#endif
