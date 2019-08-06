/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:44:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/06 18:28:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/ft_printf/includes/header.h"

# define	START	1
# define	MID		2
# define	END		3

typedef struct		s_vert
{
	char			*name;
	int				x;
	int				y;
	int				type;
	int				bfs_lvl;
	int				input_links;
	int				output_links;
	int				ant_number;
	struct s_vert	*next;
}					t_vert;

typedef struct		s_edge
{
	t_vert			*start;
	t_vert			*end;
	struct s_edge	*next;
	struct s_edge	*prev;
}					t_edge;

//typedef struct			s_ant
//{
//	t_vert				*start;
//	t_vert				*end;
//}						t_ant;

typedef struct		s_queue
{
	t_vert			*vert;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_route
{
	int 			len;
	t_edge			*start;
}					t_route;

typedef struct		s_lemin
{
	t_vert			**ants;
	t_route			*routes;
	t_vert			*verts;
	t_vert			*start;
	t_vert			*end;
	t_edge			*edges;
	int 			bfs_lvl;
	long long		ants_begin;
	long long		ants_left;
	int 			lines;
}					t_lemin;

void	main_algo(t_lemin *lemin);

/*
** READING
*/

void	read_data(t_lemin *lemin);
void	read_ants(t_lemin *lemin);
void	read_vertices(t_lemin *lemin, char **line);
void	read_edges(t_lemin *lemin, char **line);

/*
** LISTS' FUNCTIONS
*/

void	add_vert_to_lst(t_lemin *lemin, t_vert *vert);
t_vert	*create_vert(char *str, int type);
void	add_edge_to_lst(t_lemin *lemin, t_edge *edge);
t_edge	*create_edge(t_lemin *lemin, char **str);

/*
** QUEUE'S FUNCTIONS
*/

t_queue	*queue_create_elem(t_vert *vert);
void	queue_push_elem(t_queue **queue, t_queue *elem);
t_queue	*queue_get_curr_elem(t_queue **queue);
void	queue_update(t_queue **queue, t_vert *vert, t_edge *edges);

/*
** VALIDATION
*/

int		command(char *str);
int		comment(char **str);
int		room(char *str);
void	check_vert(t_lemin *lemin, t_vert *vert);
void	check_edge(t_lemin *lem_in, t_edge *edge);

/*
** ALGORITHM
*/

void	breadth_first_search(t_lemin *lemin);
void	delete_useless_edges(t_edge **edges);
void	orient_edges(t_edge *edges);
void	count_input_output_edges(t_edge *edges);
void	delete_dead_ends(t_lemin *lemin);
void	delete_in_edges(t_lemin *lemin);
void	delete_out_edges(t_lemin *lemin);
void	create_routes(t_lemin *lemin);

/*
** DELETE INPUT EDGES (AUXILIARY FUNCS)
*/

void	del_one_in_edge(t_lemin *lemin, t_vert *vert);
int		route_has_out_edge(t_lemin *lemin, t_edge *edge);
void	del_another_in_edge(t_edge **edges, t_edge *edge);

/*
** DELETE OUTPUT EDGES (AUXILIARY FUNCS)
*/

int		count_length(t_lemin *lemin, t_edge *edge, int l);
void	del_another_out_edges(t_edge **edges, t_edge *edge);
void	del_one_out_edge(t_lemin *lemin, t_vert *vert);

/*
** ROUTES
*/

void	prepare_ants(t_lemin *lemin);
void	sort_routes(t_lemin *lemin);
void	go_through_routes(t_lemin *lemin);

/*
** DISPLAYING RESULT
*/

void	print_data(t_lemin *lemin);

/*
** AUXILIARY
*/

void	err_exit(char **str);
t_vert	*find_vert(t_lemin *lemin, char *line);
t_edge	*init_link(t_vert *start, t_vert *end);
t_edge *lookfor_edge(t_lemin *lemin, t_vert *vert, int type);
void	delete_edge(t_edge **edges, t_edge *edge);

#endif
