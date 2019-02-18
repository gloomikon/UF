/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_belongs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:47:22 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:47:25 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	block_belongs(t_vector block, t_piece tet)
{
	return (vectors_equall(block, tet.coords[0]) ||
	vectors_equall(block, tet.coords[1]) ||
	vectors_equall(block, tet.coords[2]) ||
	vectors_equall(block, tet.coords[3]));
}
