/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:42:35 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 23:08:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fit_piece(t_filler *filler)
{
	check_map(filler);
	filler->result = (filler->put_or_fill == FILL) ?
		fill(filler) : put(filler);
	if (filler->result.y != -1)
	{
		ft_putnbr(filler->result.y);
		ft_putchar(' ');
		ft_putnbr(filler->result.x);
		ft_putchar('\n');
		//ft_printf("%d %d\n", filler->result.y, filler->result.x);
	}
	else
	{
		ft_printf("0 0\n");
		exit(0);
	}
}
