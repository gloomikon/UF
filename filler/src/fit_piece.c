/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:42:35 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:41:11 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fit_piece(t_filler *filler)
{
	check_map(filler);
	if (filler->direction == UP)
		filler->result = piece_put_up(filler);
	else if (filler->direction == DOWN)
		filler->result = piece_put_down(filler);
	else if (filler->direction == LEFT)
		filler->result = piece_put_left(filler);
	else if (filler->direction == RIGHT)
		filler->result = piece_put_right(filler);
	else if (filler->direction == F_LEFT)
		filler->result = piece_fill_left(filler);
	else if (filler->direction == F_RIGHT)
		filler->result = piece_fill_right(filler);
	ft_printf("%d %d\n", filler->result.y, filler->result.x);
	if (filler->result.y == 0 && filler->result.x == 0)
		exit(0);
}
