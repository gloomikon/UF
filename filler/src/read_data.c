/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:31:10 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:13:34 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
int fd;

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
	// fd = open("test.txt", O_CREAT | O_RDWR);
	// for (int i = 0; i < MH; i++)
	// 	ft_dprintf(fd, "%s\n", MI[i]);
	// for (int i = 0; i < PH; i++)
	// 	ft_dprintf(fd, "%s\n", PI[i]);
	// exit(0);
}
