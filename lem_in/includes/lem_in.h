/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:44:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/01 14:40:04 by mzhurba          ###   ########.fr       */
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
	int				bfs_level;
	int				input_links;
	int				output_links;
	int				ant_number;
	struct s_vert	*next;
}					t_vert;

typedef struct			s_edge
{
	t_vert				*start;
	t_vert				*end;
	struct s_edge		*next;
	struct s_edge		*prev;
}						t_edge;



typedef struct		s_lemin
{
	t_vert			*verts;
	t_vert			*start;
	t_vert			*end;
	t_edge			*edges;
	long long		ants_begin;
}					t_lemin;

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
** VALIDATION
*/

int		command(char *str);
int		comment(char **str);
int		room(char *str);
void	check_vert(t_lemin *lemin, t_vert *vert);
void	check_edge(t_lemin *lem_in, t_edge *edge);

/*
** AUXILIARY
*/

void	err_exit(char **str);
t_vert	*find_vert(t_lemin *lemin, char *line);
t_edge	*init_link(t_vert *start, t_vert *end);

#endif
