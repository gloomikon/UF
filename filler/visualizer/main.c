/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 03:16:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/12 04:30:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
// int	main()
// {


void	init_players(t_visualizer *v)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		free(line);
	}
	get_next_line(0, &line);
	v->p1 = ft_strdup(ft_strrchr(line, '/') + 1);
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	v->p2 = ft_strdup(ft_strrchr(line, '/') + 1);
	free(line);
}

void	draw_top(int width)
{
	mvaddstr(0, 5 , "███████╗██╗██╗     ██╗     ███████╗██████╗  \n");
	mvaddstr(1, 5 , "██╔════╝██║██║     ██║     ██╔════╝██╔══██╗ \n");
	mvaddstr(2, 5 , "█████╗  ██║██║     ██║     █████╗  ██████╔╝ \n");
	mvaddstr(3, 5 , "██╔══╝  ██║██║     ██║     ██╔══╝  ██╔══██╗ \n");
	mvaddstr(4, 5 , "██║     ██║███████╗███████╗███████╗██║  ██║ \n");
	mvaddstr(5, 5 , "╚═╝     ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝ \n");
	mvaddstr(6, 5 , "                  by Колумбия               \n");
}

void	read_size(char *line, t_visualizer *v) //rewrite
{
	char	**sizes;

	sizes = ft_strsplit(line, ' ');
	v->map_size.y = ft_atoi(sizes[1]);
	v->map_size.x = ft_atoi(sizes[2]);
	// ft_arrclr(sizes);
}


void	init_screen(char *line, t_visualizer *v)
{
	int width;

	width = (v->map_size.x > 50) ? v->map_size.x * 2 : 50;
	setlocale(LC_ALL, "");
	initscr();
	curs_set(0);
	v->size = COLS * LINES;
	read_size(line, v);
	refresh();
	v->score = newwin(7, width, 10, 5);
	v->map = newwin(v->map_size.y + 2, (v->map_size.x + 2) * 2, 20,
		(width == v->map_size.x * 2) ? 5 : (5 + (width - v->map_size.x)));
	mvwaddstr(v->score, 1, width / 2 - ft_strlen(v->p1), v->p1);
	mvwaddstr(v->score, 1, width * 2 - (width / 2) - ft_strlen(v->p2) / 2, v->p2);
	box(v->score, 0, 0);
	box(v->map, 0, 0);
	wrefresh(v->score);
	draw_top(width);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
}

int main(void)
{
	char			*line;
	t_visualizer	v;

	ft_bzero(&v, sizeof(t_visualizer));
	init_players(&v);
	while (69)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "Plateau") && v.map_size.y == 0)
			init_screen(line, &v);
	}
}