/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:30:51 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 22:45:13 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	filler;

	ft_bzero(&filler, sizeof(t_filler));
	get_player(&filler);
	while (69)
	{
		read_data(&filler);
		fit_piece(&filler);
	}
	return (0);
}
