/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:51:50 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 21:51:57 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_filler(int put_or_fill, t_point from, t_point to, t_filler *filler)
{
	filler->put_or_fill = put_or_fill;
	filler->from = from;
	filler->to = to;
}
