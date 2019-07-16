/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:30:51 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 20:26:43 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	filler;

	ft_bzero(&filler, sizeof(t_filler));
	get_player(&filler);
	while (1)
	{
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		read_data(&filler);
		fit_piece(&filler);
		
		//exit(1);
	}
	return (0);
}
