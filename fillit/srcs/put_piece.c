/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:29:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:29:24 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	put_piece(t_vector ptn, t_piece tet, char **sqr, char c)
{
	*(*(sqr + ptn.y + tet.coords[0].y) + ptn.x + tet.coords[0].x) = c;
	*(*(sqr + ptn.y + tet.coords[1].y) + ptn.x + tet.coords[1].x) = c;
	*(*(sqr + ptn.y + tet.coords[2].y) + ptn.x + tet.coords[2].x) = c;
	*(*(sqr + ptn.y + tet.coords[3].y) + ptn.x + tet.coords[3].x) = c;
	return (1);
}
