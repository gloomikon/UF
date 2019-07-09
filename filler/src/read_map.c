/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:41:38 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 19:41:38 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	read_map(t_filler *filler)
{
	char	*line;
	char	**splitted;
	int		i;

	get_next_line(0, &line);
	splitted = ft_strsplit(line, ' ');
	filler->board.height = ft_atoi(splitted[1]);
	filler->board.width = ft_atoi(splitted[2]);
	filler->board.size = filler->board.height * filler->board.width;
	filler->board.info = ft_memalloc(sizeof(char*) * (filler->board.height + 1));
	ft_splitdel(splitted);
	get_next_line(0, &line);
	ft_strdel(&line);
	i = -1;
	while (++i < filler->board.height)
	{
		get_next_line(0, &line);
		filler->board.info[i] = ft_strdup(line + 4);
		ft_strdel(&line);
	}
}
