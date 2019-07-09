/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:49:26 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 18:49:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player(t_filler *filler)
{
	char *line;

	if (get_next_line(0, &line) && line)
	{
		filler->me.symbol = 70 + (line[10] - '0') * 9;
		filler->bot.symbol = 97 - (line[10] - '0') * 9;
		ft_strdel(&line);
		return (0);
	}
	else
		return (1);
}