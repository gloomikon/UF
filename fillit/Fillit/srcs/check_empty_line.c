/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:46:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:46:54 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_empty_line(char **line, t_piece *piece)
{
	if (ft_strlen(*line))
		piece->coords[0] = create_vector_from_coords(-2, -2);
	ft_strdel(line);
}
