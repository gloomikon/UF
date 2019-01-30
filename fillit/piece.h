/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:37:19 by mzhurba           #+#    #+#             */
/*   Updated: 2019/01/24 12:40:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_H
# define PIECE_H

typedef struct	s_coords
{
	int	x;
	int y;
}				t_coords;

typedef struct	s_piece
{
	t_coords	crds[4];
}				t_piece;

#endif
