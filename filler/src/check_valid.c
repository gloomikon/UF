/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:49:34 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 18:08:13 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_valid(t_filler *filler, int y, int x)
{
	int i;
	int j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < filler->piece.height && (j = -1))
		while (++j < filler->piece.width)
		{
			if (filler->piece.info[i][j] == '*' &&
				(invalid_pos(y + i, x + j, filler->map) ||
				(filler->map.info[y + i][x + j] == filler->bot ||
				filler->map.info[y + i][x + j] == filler->bot + 32)))
				return (0);
			if (filler->piece.info[i][j] == '*' &&
				(filler->map.info[y + i][x + j] == ME))
				cnt++;
		}
	return (cnt == 1);
}
