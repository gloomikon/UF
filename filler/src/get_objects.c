/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:10:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 19:10:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

int		dist(t_point a, t_point b)
{
	return (ft_abs(a.x - b.x) + ft_abs(a.y - b.y));
}

void		create_arrays(t_filler *filler)
{
	if (filler->buf_enemy)
		ft_memdel((void **)&filler->buf_enemy);
	if (filler->buf_player)
		ft_memdel((void **)&filler->buf_player);
	if (!(filler->buf_player = ft_memalloc(filler->board.size * sizeof(t_point))) ||
		!(filler->buf_enemy = ft_memalloc(filler->board.size * sizeof(t_point))))
		exit(1);
	// ft_bzero(filler->buf_player, size * sizeof(t_point));
	// ft_bzero(filler->buf_enemy, size * sizeof(t_point));
}

void		populate_closest_array(t_filler *filler)
{
	t_point	point;

	create_arrays(filler);
	ft_bzero(&filler->count, sizeof(t_point));
	// filler->p_count = 0;
	// filler->e_count = 0;
	point.y = -1;
	while (++point.y < filler->board.height && (point.x = -1))
		while (++point.x < filler->board.width)
		{
			if (filler->board.info[point.y][point.x] == filler->me.symbol)
				filler->buf_player[filler->count.x++] = point;
			else if (filler->board.info[point.y][point.x] == filler->bot.symbol)
				filler->buf_enemy[filler->count.y++] = point;
		}
}

t_point		create_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return point;
}

static int	position_valid(t_filler filler, t_point point)
{
	return (point.x >= 0 && point.y >= 0 &&
			point.x < filler.board.width && point.y < filler.board.height);
}


int			try_place(t_filler filler, t_point point)
{
	t_point	p;
	int		count;

	if (point.y + filler.piece.height > filler.board.height ||
		point.x + filler.piece.width > filler.board.width)
		return (2);
	count = 0;
	p.y = -1;
	while (++p.y < filler.piece.height && (p.x = -1))
		while (++p.x < filler.piece.width)
			if (filler.piece.info[p.y][p.x] == '*' &&
		((filler.board.info[point.y + p.y][point.x + p.x] == filler.me.symbol) && ++count > 1) ||
		(filler.board.info[point.y + p.y][point.x + p.x] == filler.bot.symbol))
				return (1);
	// return (count < 1 ? 1 : 0);
	return (!count);
}


static int			place_around(t_filler filler, t_point p, t_point *result)
{
	t_point		offset;

	offset.y = -1;
	while (++offset.y < filler.piece.height && (offset.x = -1))
		while (++offset.x < filler.piece.width)
		{
			*result = create_point(p.x - offset.x, p.y - offset.y);
			// result->x = p.x - offset.x;
			// result->y = p.y - offset.y;
			if (filler.piece.info[offset.y][offset.x] == '*' &&
					position_valid(filler, *result) &&
					!try_place(filler, *result))
				return (1);
		}
	return (0);
}

t_point		find_placement(t_filler filler) //looks like shit
{
	t_point p;
	t_point temp;

	p.y = filler.target.y;
	while (filler.target.y == 0 ? p.y < filler.board.height : p.y >= 0)
	{
		p.x = filler.target.x;
		while (filler.target.x == 0 ? p.x < filler.board.width : p.x >= 0)
		{
			if (filler.board.info[p.y][p.x] == filler.me.symbol &&
					place_around(filler, p, &temp))
				return (temp);
			p.x += (filler.target.x == 0 ? 1 : -1);
		}
		p.y += (filler.target.y == 0 ? 1 : -1);
	}
	return (p);
}


static t_point		closest_pair(t_filler *filler)
{
	int		player;
	int		enemy;
	t_point	temp;
	t_point	p;
	int		last_dist;

	populate_closest_array(filler);
	last_dist = filler->board.width + filler->board.height + 1;
	player = -1;
	while (++player < filler->count.x && (enemy = -1))
		while (++enemy < filler->count.y)
		{
			if (dist(filler->buf_player[player], filler->buf_enemy[enemy]) <= last_dist &&
					place_around(*filler, filler->buf_player[player], &temp))
			{
				p = temp;
				last_dist = dist(filler->buf_player[player], filler->buf_enemy[enemy]);
			}
		}
	return (last_dist == filler->board.width + filler->board.height + 1 ?
		find_placement(*filler) : p);
}

static void place(t_filler *filler)
{
	t_point		candidate;

	candidate = closest_pair(filler);
	if (!position_valid(*filler, candidate))
	{
		candidate.x = 0;
		candidate.y = 0;
		ft_printf("%d %d\n", candidate.y, candidate.x);
		exit(0);
	}
	ft_printf("%d %d\n", candidate.y, candidate.x);
}

static void init(t_filler *filler)
{
	t_point p;

	filler->inited = 1301;
	p.y = -1;
	while (++p.y < filler->board.height && (p.x = -1))
		while (++p.x < filler->board.width)
		{
			if (filler->board.info[p.y][p.x] == filler->me.symbol)
				filler->me.start = p;
			else if (filler->board.info[p.y][p.x] == filler->bot.symbol)
				filler->bot.start = p;
		}
	filler->target.y = (filler->bot.start.y - filler->me.start.y >= 0 ?
			DOWN : UP);
	filler->target.x = (filler->bot.start.x - filler->me.start.x >= 0 ?
			RIGHT : LEFT);
}

static void	free_token(t_object *obj, int offset)
{
	int		i;
	char	*tmp;

	if (!obj->info)
		return ;
	i = -1;
	while (++i < obj->height)
	{
		tmp = obj->info[i] - offset;
		ft_strdel(&tmp);
	}
	ft_memdel((void **)&obj->info);
}

static void	read_token(char *line, int offset, t_object *obj)
{
	char	**splitted;
	int		i;

	free_token(obj, offset);
	splitted = ft_strsplit(line, ' ');
	obj->height = ft_atoi(splitted[1]);
	obj->width = ft_atoi(splitted[2]);
	obj->size = obj->height * obj->width;
	ft_splitdel(splitted);
	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	obj->info = ft_memalloc(obj->height * sizeof(char *));
	i = -1;
	while (++i < obj->height)
	{
		get_next_line(0, &line);
		obj->info[i] = line + offset;
	}
}

static void read_map(char *line, t_filler *filler)
{
	read_token(line, 4, &(filler->board));
	if (!filler->inited)
		init(filler);
}

static void	read_piece(char *line, t_filler *filler)
{
	read_token(line, 0, &(filler->piece));
	place(filler);
}

void		filler_loop(t_filler *filler)
{
	char	*line;
	int		res;

	while ((res = get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue;
		// (!ft_strncmp(line, "Plateau", 7)) ? read_map(line, filler) :
		// 	read_piece(line, filler);
		if (!ft_strncmp(line, "Piece", 5))
			read_piece(line, filler);
		else if (!ft_strncmp(line, "Plateau", 7))
			read_map(line, filler);
		ft_strdel(&line);
	}
}
