/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:28:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 14:28:55 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*invalid_piece(t_piece *curr, char **line)
{
	ft_strdel(line);
	curr->coords[0] = create_vector_from_coords(-2, -2);
	return (curr);
}
