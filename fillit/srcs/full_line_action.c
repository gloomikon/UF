/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_line_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:54:36 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:30:23 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	full_line_action(t_vector *iters, char *line,
							int *points, t_piece *curr)
{
	static t_vector first_point;

	while (++iters->y < 4)
		if (line[iters->y] == '#')
			vector_from_piece(create_vector_from_coords(iters->y,
						iters->x), &first_point, points, curr);
	ft_strdel(&line);
}
