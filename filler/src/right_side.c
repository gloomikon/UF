/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_side.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:47:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:47:30 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		right_side(t_filler *filler)
{
	int y;

	if (ft_strchr(MI[0], filler->me))
		return (1);
	y = -1;
	while (++y < MH)
		if (MI[y][MW - 1] == filler->me)
			return (1);
	return (0);
}
