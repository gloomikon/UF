/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:01:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 22:01:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf/includes/header.h"
# include <fcntl.h>

# define EQUALS(a, b)	(a == b) || (a == b + 32)

# define UP_LEFT	7
# define DOWN_RIGHT 3

# define UP			8
# define LEFT		4
# define RIGHT		6
# define DOWN		2

# define FILL_LEFT	0
# define FILL_RIGHT	1

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_object
{
	int			height;
	int			width;
	int			size;
	char		**info;
}				t_object;

typedef struct	s_filler
{
	char		me;
	char		bot;
	t_object	map;
	t_object	piece;
	t_point		diff;
	int			corner;
	int			direction;
	t_point		result;
}				t_filler;


#endif	