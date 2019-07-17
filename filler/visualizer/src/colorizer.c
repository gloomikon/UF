/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:35:07 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:54:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	colorizer(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(9, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_CYAN, COLOR_BLACK);
	init_pair(12, COLOR_ORANGE, COLOR_BLACK);
	init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, 225);
	init_pair(15, 52, 225);
}
