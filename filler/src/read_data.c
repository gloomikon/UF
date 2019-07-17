/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:31:10 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 22:44:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		read_data(t_filler *filler)
{
	char	*line;

	get_next_line(0, &line);
	read_map(line, &filler->map);
	ft_strdel(&line);
	filler->corner = (filler->corner) ? filler->corner : init_corner(filler);
	get_next_line(0, &line);
	read_piece(line, &filler->piece);
	ft_strdel(&line);
}
