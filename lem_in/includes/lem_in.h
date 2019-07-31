/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:44:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/31 15:27:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/ft_printf/includes/header.h"
# include <limits.h>

# define	START	1
# define	MID		2
# define	END		3

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				type;
	int				bfs_level;
	int				input_links;
	int				output_links;
	int				ant_number;
	struct s_room	*next;
}					t_room;

typedef struct		s_line
{
	char			*line;
	struct s_line	*nxt;
}					t_line;

typedef struct		s_lemin
{
	t_line			*lines;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	long long		ants_begin;
}					t_lemin;

void	read_ants(t_lemin *lemin);
char	*read_next_line(t_line **lines);
void	err_exit(void);

#endif
