/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector_from_coords.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:50:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:50:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_vector	create_vector_from_coords(int x, int y)
{
	t_vector	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}
