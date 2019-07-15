/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:31:51 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:55:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	init_header(t_visualizer *v)
{
	v->header = newwin(7, 200, 1, 5);
	wattron(v->header, COLOR_PAIR(5));
	mvwaddstr(v->header, 0, (MX - 17),
		"███████╗██╗██╗     ██╗     ███████╗██████╗  \n");
	wattron(v->header, COLOR_PAIR(12));
	mvwaddstr(v->header, 1, (MX - 17),
		"██╔════╝██║██║     ██║     ██╔════╝██╔══██╗ \n");
	wattron(v->header, COLOR_PAIR(10));
	mvwaddstr(v->header, 2, (MX - 17),
		"█████╗  ██║██║     ██║     █████╗  ██████╔╝ \n");
	wattron(v->header, COLOR_PAIR(3));
	mvwaddstr(v->header, 3, (MX - 17),
		"██╔══╝  ██║██║     ██║     ██╔══╝  ██╔══██╗ \n");
	wattron(v->header, COLOR_PAIR(11));
	mvwaddstr(v->header, 4, (MX - 17),
		"██║     ██║███████╗███████╗███████╗██║  ██║ \n");
	wattron(v->header, COLOR_PAIR(9));
	mvwaddstr(v->header, 5, (MX - 17),
		"╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝ \n");
	wattron(v->header, COLOR_PAIR(13));
	mvwaddstr(v->header, 6, (MX - 17),
		"              by КолумбиЯ               \n");
	wrefresh(v->header);
}
