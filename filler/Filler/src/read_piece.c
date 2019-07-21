/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:35:54 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:36:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_piece(char *line, t_object *piece)
{
	char	*tmp;
	int		i;

	tmp = ft_strchr(line, ' ') + 1;
	piece->height = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	piece->width = ft_atoi(tmp);
	piece->info = ft_memalloc(sizeof(char *) * piece->height);
	i = -1;
	while (++i < piece->height)
		get_next_line(0, &piece->info[i]);
}
