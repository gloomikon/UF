/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:44:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/16 18:49:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_ul(t_filler *filler)
{
	if (left_side(filler) && ft_strchr(MI[0], ME))
		filler->direction = F_LEFT;
	else if (filler->diff.y > filler->diff.x)
		filler->direction = ft_strchr(MI[0], ME) ?
			LEFT : UP;
	else
		filler->direction = left_side(filler) ? UP : LEFT;
}
