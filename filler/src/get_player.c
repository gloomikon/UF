/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:37:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:38:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_filler *filler)
{
	char *line;

	get_next_line(0, &line);
	filler->me = 70 + (line[10] - '0') * 9;
	filler->bot = 97 - (line[10] - '0') * 9;
	ft_strdel(&line);
}
