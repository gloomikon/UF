/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 03:16:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 19:04:22 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	main(void)
{
	char			*line;
	t_visualizer	v;

	ft_bzero(&v, sizeof(t_visualizer));
	init_players(&v);
	while (69)
	{
		get_next_line(0, &line);
		if (!ft_strncmp(line, "Plateau", 7) && v.map_size.y == 0)
			init_screen(line, &v);
		else if (ft_strstr(line, "0123456789"))
			update(&v);
		else if (ft_strstr(line, "== X"))
			break ;
		usleep(DELAY);
	}
	ft_strdel(&line);
	init_winner(&v);
	end_free(&v);
	return (0);
}
