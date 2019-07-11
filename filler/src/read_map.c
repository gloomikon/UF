/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:36:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:36:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(char *line, t_object *map)
{
	char	*tmp;
	int		i;

	tmp = ft_strchr(line, ' ') + 1;
	map->height = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	map->width = ft_atoi(tmp);
	map->info = ft_memalloc(sizeof(char *) * map->height);
	i = -1;
	get_next_line(0, &tmp);
	free(tmp);
	while (++i < map->height)
	{
		get_next_line(0, &tmp);
		map->info[i] = ft_strdup(tmp + 4);
		free(tmp);
	}
}
