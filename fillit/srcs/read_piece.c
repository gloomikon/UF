/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:31:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:32:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		read_piece(int fd)
{
	t_piece		curr;
	t_vector	iters;
	t_vector	pts_ret;
	char		*line;

	iters.x = 0;
	pts_ret.x = -1;
	while (iters.x < 4 && ((iters.y = -1)))
	{
		if (!(pts_ret.y = GNL(fd, &line)))
			curr.coords[0] = create_vector_from_coords(-1, -1);
		else if (check_full_line(line, &curr))
			full_line_action(&iters, line, &pts_ret.x, &curr);
		else
			return (*invalid_piece(&curr, &line));
		if (!end_action(pts_ret.y, &iters.x))
			break ;
	}
	if (pts_ret.x != 3 && pts_ret.x != -1)
		curr.coords[0] = create_vector_from_coords(-2, -2);
	if ((piece_valid(&curr) || 1) && GNL(fd, &line))
		check_empty_line(&line, &curr);
	return (curr);
}
