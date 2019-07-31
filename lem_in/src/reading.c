/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:20:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/31 15:24:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ants(t_lemin *lemin)
{
	char	*line;

	if ((line = read_next_line(&lemin->lines)))
	{
		if (!ft_isnumber(line, 10)
		|| (lemin->ants_begin = ft_atoi(line)) < 1
		|| (lemin->ants_begin > INT_MAX))
			err_exit();
	}
}
