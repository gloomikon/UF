/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/02 16:55:40 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_ants(t_lemin *lemin)
{
	int i;

	i = -1;
	lemin->ants = (t_ant*)ft_memalloc(sizeof(t_ant) * lemin->ants_begin);
	while (++i < lemin->ants_begin)
		lemin->ants[i].start = lemin->start;
}

/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	read_data(&lemin);
	create_ants(&lemin);
	printf("SUCCESS\n");
	system("leaks -q a.out");
}
