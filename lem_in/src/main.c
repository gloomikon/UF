/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:14:38 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/31 18:12:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** HELP
*/

void	err_exit(void)
{
	system("leaks -q lem_in");
	ft_printf("ERROR\n");
	exit(1);
}

/*
** MOVE TO LIBFT
*/

int	ft_strsplit_len(char **split)
{
	int i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		++i;
	return (i);
}

void	free_split_array(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
}

/*
**	LIST   ЗАЧЕМ МНЕ БЛЯТЬ ЭТО ВООБЩЕ НАДО???
*/

t_line	*lst_create(char *new)
{
	t_line *line;

	line = (t_line*)malloc(sizeof(t_line));
	line->line = new;
	line->nxt = NULL;
	return (line);
}

void	lst_push(t_line **lines, t_line *line)
{
	t_line *current;

	if (lines && *lines && line)
	{
		current = *lines;
		while (current->nxt)
			current = current->nxt;
		current->nxt = line;
	}
	else if (lines && line)
		*lines = line;
}

/*
** LIST OF ROOMS
*/

void	add_room_to_lst(t_lemin *lemin, t_room *rm)
{
	t_room *current;

	if ((current = lemin->rooms))
	{
		while (current->next)
			current = current->next;
		current->next = rm;
	}
	else
		lemin->rooms = rm;
	(rm->type == START) ? lemin->start = rm : 0;
	(rm->type == END) ? lemin->end = rm : 0;
}

t_room	*create_room(char *str, int type)
{
	char	**split;
	t_room	*rm;

	split = ft_strsplit(str, ' ');
	rm = (t_room *)ft_memalloc(sizeof(t_room));
	rm->name = ft_strdup(split[0]);
	rm->type = type;
	rm->x = ft_atoi(split[1]);
	rm->y = ft_atoi(split[2]);
	rm->input_links = 0;
	rm->output_links = 0;
	rm->bfs_level = -1;
	rm->ant_number = -1;
	rm->next = NULL;
	free_split_array(split);
	return (rm);
}

/*
** VALIDATION
*/

int	command(char *str)
{
	if (!ft_strncmp(str, "##", 2)) // len > 2 ?
	{
		if (!ft_strcmp(str, "##start"))
			return (START);
		else if (!ft_strcmp(str, "##end"))
			return (END);
		else
			return (MID);
	}
	return (0);
}

int	comment(char *str)
{
	if (!command(str) && !ft_strncmp(str, "#", 1))
		return (1);
	return (0);
}

int	room_name(char *str)
{
	if (str[0] != 'L' && str[0] != '#')
		return (1);
	return (0);
}

int	room(char *str)
{
	int		result;
	char	**split;

	result = 0;
	split = ft_strsplit(str, ' ');
	if (ft_strsplit_len(split) == 3
	&& room_name(split[0])
	&& ft_isnumber(split[1], 10)
	&& ft_isnumber(split[2], 10))
		result = 1;
	free_split_array(split);
	return (result);
}

void		validate(t_lemin *lemin, t_room *rm)
{
	t_room	*rooms;

	rooms = lemin->rooms;
	while (rooms)
	{
		if (rm != rooms
			&& (!ft_strcmp(rm->name, rooms->name)
				|| (rm->x == rooms->x && rm->y == rooms->y)))
			err_exit();
		rooms = rooms->next;
	}
}

/*
** READING
*/

char	*read_next_line(t_line **lines)
{
	char	*curr;

	if (get_next_line(0, &curr))
		lst_push(lines, lst_create(curr));
	return (curr);
}

void	read_map(t_lemin *lemin)
{
	int		type_of_room;
	t_room	*rm;
	char	*curr;

	type_of_room = MID;
	while ((curr = read_next_line(&lemin->lines)))
	{
		if (comment(curr))
			type_of_room = MID;
		else if (command(curr))
		{
			type_of_room = command(curr);
			if ((type_of_room == START && lemin->start)
			|| (type_of_room == END && lemin->end))
				err_exit();
		}
		else if (room(curr))
		{
			validate(lemin, (rm = create_room(curr, type_of_room)));
			add_room_to_lst(lemin, rm);
			type_of_room = MID;
		}
		else
			break ;
	}
}

void	read_data(t_lemin *lemin)
{
	read_ants(lemin);
	read_map(lemin);
}

/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;
	t_room	*rm;

	ft_bzero(&lemin, sizeof(t_lemin));
//	if (argc != 1)
//		err_exit();
	read_data(&lemin);
	rm = lemin.rooms;
	printf("SUCCESS\n%lld\n%s\n", lemin.ants_begin, lemin.lines->line);
	while (rm)
	{
		printf("%s %d %d\n", rm->name, rm->x, rm->y);
		rm = rm->next;
	}
	system("leaks -q lem_in");
}
