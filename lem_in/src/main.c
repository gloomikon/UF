/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:43:05 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/30 18:14:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_exit(void)
{
	system("leaks -q a.out");
	ft_printf("ERROR\n");
	exit(1);
}

/*
**	LIST
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
** READING
*/

char	*read_next_line(t_line **lines)
{
	int		res;
	char	*gnl;

	if ((res = get_next_line(0, &gnl)) > 0)
		lst_push(lines, lst_create(gnl));
	return (gnl);
}

void	read_ants(t_lemin *lemin)
{
	char	*line;

	if ((line = read_next_line(&lemin->lines)))
	{
		if (!ft_isnumber(line, 10)
		|| (lemin->ants_begin = ft_atoi(line)) < 1)
			err_exit();
	}
}

void	read_data(t_lemin *lemin)
{
	read_ants(lemin);
}

/*
** MAIN
*/

int	main(int argc, char **argv)
{
	t_lemin	lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	if (argc != 1)
		err_exit();
	read_data(&lemin);
	ft_printf("%d\n%s\n", lemin.ants_begin, lemin.lines->line);
	system("leaks -q a.out");
}
