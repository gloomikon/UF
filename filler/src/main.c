/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:30:51 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/11 05:07:47 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int fd;



void	read_piece(char *line, t_object *piece)
{
	char	*tmp;
	int		i;

	tmp = ft_strchr(line, ' ') + 1;
	piece->height = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	piece->width = ft_atoi(tmp);
	piece->info = ft_memalloc(sizeof(char *) * piece->height);
	i = -1;
	while (++i < piece->height)
		get_next_line(0, &piece->info[i]);
}

void	read_map(char *line, t_object *map)
{
	char	*tmp;
	int		i;

	tmp = ft_strchr(line, ' ') + 1;
	map->height = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	map->width = ft_atoi(tmp);
	map->info = ft_memalloc(sizeof(char *) * map->height);
	//ft_dprintf(fd, "map: %d %d\n", map->height, map->width);
	i = -1;
	get_next_line(0, &tmp);
	free(tmp);
	while (++i < map->height)
	{
		get_next_line(0, &tmp);
		map->info[i] = ft_strdup(tmp + 4);
		free(tmp);
	}
}

void	print_data(t_filler *filler)
{
	// //ft_dprintf(fd, "MAP\n");
	// for (int i = 0; i < filler->map.height; ++i)
	// 	//ft_dprintf(fd, "%s\n", filler->map.info[i]);
	// 	//ft_dprintf(fd, "\nPIECE\n");
	// for (int i = 0; i < filler->piece.height; ++i)
	// 	//ft_dprintf(fd, "%s\n", filler->piece.info[i]);
}

int		init_corner(t_filler *filler)
{
	t_point loop;

	loop.y = -1;
	while (++loop.y < filler->map.height && (loop.x = -1))
		while (++loop.x < filler->map.width)
			if (filler->map.info[loop.y][loop.x] == filler->me)
				return (UP_LEFT);
			else if (filler->map.info[loop.y][loop.x] == filler->bot)
				return(DOWN_RIGHT);
	return (0);
}

void	read_data(t_filler *filler)
{
	char	*line;

	get_next_line(0, &line);
	read_map(line, &filler->map);
	filler->corner = (filler->corner) ? filler->corner : init_corner(filler);
	free(line);
	get_next_line(0, &line);
	read_piece(line, &filler->piece);
	print_data(filler);
}

void	get_player(t_filler *filler)
{
	char *line;

	get_next_line(0, &line);
	//ft_dprintf(fd, "%s\n", line);
	filler->me = 70 + (line[10] - '0') * 9;
	filler->bot = 97 - (line[10] - '0') * 9;
	//ft_dprintf(fd, "me = %c bot = %c\n", filler->me, filler->bot);
	ft_strdel(&line);
}

int		get_top(t_object map, char who)
{
	t_point loop;

	loop.y = -1;
	while (++loop.y < map.height && (loop.x = -1))
		while (++loop.x < map.width)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.y);
	return (0);
}

int		get_bottom(t_object map, char who)
{
	t_point loop;

	loop.y = map.height;
	while (--loop.y >= 0 && (loop.x = -1))
		while (++loop.x < map.width)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.y);
	return (0);
}

int		get_left(t_object map, char who)
{
	t_point loop;

	loop.x = -1;
	while (++loop.x < map.width && (loop.y = -1))
		while (++loop.y < map.height)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.x);
	return (map.width + 1);
}

int		get_right(t_object map, char who)
{
	t_point loop;

	loop.x = map.width;
	while (--loop.x >= 0 && (loop.y = -1))
		while (++loop.y < map.height)
			if (EQUALS(map.info[loop.y][loop.x], who))
				return (loop.x);
	return (-1);
}

int		left_side(t_filler *filler)
{
	int	y;

	if (ft_strchr(filler->map.info[filler->map.height -1], filler->me))
		return (1);
	y = -1;
	while (++y < filler->map.height)
		if (filler->map.info[y][0] == filler->me)
			return (1);
	return (0);
}

void	check_ul(t_filler *filler)
{
	if (left_side(filler) && ft_strchr(filler->map.info[0], filler->me))
		filler->direction = FILL_LEFT;
	else if (filler->diff.y > filler->diff.x)
		filler->direction = ft_strchr(filler->map.info[0], filler->me) ?
			LEFT : UP;
	else
		filler->direction = (left_side(filler)) ? UP : LEFT;
}

int		right_side(t_filler *filler)
{
	int y;

	if (ft_strchr(filler->map.info[0], filler->me))
		return (1);
	y = -1;
	while(++y < filler->map.height)
		if (filler->map.info[y][filler->map.width - 1] == filler->me)
			return (1);
	return (0);
}

void	check_dr(t_filler *filler)
{
	if (right_side(filler) &&
		ft_strchr(filler->map.info[filler->map.height - 1], filler->me))
		filler->direction = FILL_RIGHT;
	else if (filler->diff.y > filler->diff.x)
		filler->direction = ft_strchr(filler->map.info[filler->map.height - 1],
			filler->me) ? RIGHT : DOWN;
	else
		filler->direction = (right_side(filler)) ? DOWN : RIGHT;
}

void	check_map(t_filler *filler)
{
	// filler->diff = (filler->corner == DOWN_RIGHT) ?
	// create_point(get_left(filler->map, filler->me) -
	// 			get_right(filler->map, filler->bot),
	// 				get_top(filler->map, filler->me) -
	// 				get_bottom(filler->map, filler->bot)) :
	// create_point(get_left(filler->map, filler->bot) -
	// 			get_right(filler->map, filler->me),
	// 				get_top(filler->map, filler->bot) -
	// 				get_bottom(filler->map, filler->me));
	// filler->corner == DOWN_RIGHT ? check_ul(filler) : check_dr(filler);
	// //ft_dprintf(fd, "diff : %d %d\n", filler->diff.y, filler->diff.x);
		if (filler->corner == DOWN_RIGHT)
	{
		filler->diff.y = get_top(filler->map, filler->me);
		filler->diff.y -= get_bottom(filler->map, filler->bot);
		filler->diff.x = get_left(filler->map, filler->me);
		filler->diff.x -= get_right(filler->map, filler->bot);
		check_ul(filler);
	}
	else if (filler->corner == UP_LEFT)
	{
		filler->diff.y = get_top(filler->map, filler->bot);
		filler->diff.y -= get_bottom(filler->map, filler->me);
		filler->diff.x = get_left(filler->map, filler->bot);
		filler->diff.x -= get_right(filler->map, filler->me);
		check_dr(filler);
	}
	//ft_dprintf(fd, "diff : %d %d\n", filler->diff.y, filler->diff.x);

}

int		invalid_pos(int y, int x, t_object map)
{
	if (y < 0 || x < 0 ||
		y >= map.height || x >= map.width)
		return (1);
	return (0);
}

int		check_valid(t_filler *filler, int y, int x)
{
	int i;
	int j;
	int	cnt;

	//ft_dprintf(fd, "checking %d %d\n", y, x);

	i = -1;
	cnt = 0;
	while (++i < filler->piece.height)
	{
		j = -1;
		while (++j < filler->piece.width)
		{
			if (filler->piece.info[i][j] == '*' &&
				(invalid_pos(y + i, x + j, filler->map) || 
				(filler->map.info[y + i][x + j] == filler->bot ||
				filler->map.info[y + i][x + j] == filler->bot + 32)))
				return (0);
			if (filler->piece.info[i][j] == '*' && (filler->map.info[y + i][x + j] == filler->me))
				cnt++;
		}
	}
	//ft_dprintf(fd, "checked! %d %d cnt=%d\n", y, x, cnt);
	return (cnt == 1 ? 1 : 0);
}

int	put_fill_right(t_filler *filler)
{
	int y;
	int x;

	x = filler->map.width;
	while (--x >= 0)
	{
		y = filler->map.height;
		while (--y >= 0)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol fill right= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int	put_fill_left(t_filler *filler)
{
	int y;
	int x;

	x = -1;
	while (++x < filler->map.width)
	{
		y = -1;
		while (++y < filler->map.height)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol fill left= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int	put_down(t_filler *filler)
{
	int y;
	int x;

	y = filler->map.height;
	while (--y >= 0)
	{
		x = filler->map.width;
		while (--x >= 0)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol put down= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int	put_right(t_filler *filler)
{
	int y;
	int x;

	y = -1;
	while (++y < filler->map.height)
	{
		x = filler->map.width;
		while (--x >= 0)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol put rigth= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int	put_left(t_filler *filler)
{
	int y;
	int x;

	y = filler->map.height;
	while (--y >= 0)
	{
		x = -filler->piece.width;
		while (++x < filler->map.width)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol put left= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}

int	put_up(t_filler *filler)
{
	int y;
	int x;

	y = -filler->piece.height;
	while (++y < filler->map.height)
	{
		x = -filler->piece.width;
		while (++x < filler->map.width)
		{
			if (check_valid(filler, y, x))
			{
				filler->result.y = y;
				filler->result.x = x;
				//ft_dprintf(fd, "prikol put up= %d %d\n", y, x);
				return (1);
			}
		}
	}
	return (0);
}


void	fit_piece(t_filler *filler)
{
	int rs = 0;
	check_map(filler);
	//ft_dprintf(fd, "direction = %d\n", filler->direction);
	if (filler->direction == UP)
		rs = put_up(filler);
	else if (filler->direction == LEFT)
		rs = put_left(filler);
	else if (filler->direction == RIGHT)
		rs = put_right(filler);
	else if (filler->direction == DOWN)
		rs = put_down(filler);
	else if (filler->direction == FILL_LEFT)
		rs = put_fill_left(filler);
	else if (filler->direction == FILL_RIGHT)
		rs = put_fill_right(filler);
	//ft_dprintf(fd, "res = %d\n%d %d\n\n", rs, filler->result.y, filler->result.x);
	if (rs)
	{
		// ft_putnbr_fd(filler->result.y, 0);
		// ft_putchar_fd(' ', 0);
		// ft_putnbr_fd(filler->result.x, 0);
		// ft_putchar_fd('\n', 0);
		ft_printf("%d %d\n", filler->result.y, filler->result.x);
		//ft_dprintf(fd, "result = %d %d\n\n---------------\n\n", filler->result.y, filler->result.x);
	}
	else
	{
		ft_printf("0 0\n");
		exit(0);
	}
}

int		main(void)
{
	t_filler	filler;

	fd = open("text.txt", O_RDWR | O_CREAT);
	ft_bzero(&filler, sizeof(t_filler));
	get_player(&filler);
	while (1)
	{
	read_data(&filler);
	fit_piece(&filler);
	}
	return (0);
}
