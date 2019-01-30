/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:22:58 by mzhurba           #+#    #+#             */
/*   Updated: 2019/01/30 16:51:26 by mzhurba          ###   ########.fr       */
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

int			check_full_line(char *str, t_piece *piece)
{
	int i;

	if (ft_strlen(str) != 4)
	{
		piece->coords[0] = create_vector_from_coords(-2, -2);
		return (0);
	}
	i = -1;
	while (str[++i])
		if (!(str[i] == '.' || str[i] == '#'))
		{
			piece->coords[0] = create_vector_from_coords(-2, -2);
			return (0);
		}
	return (1);
}

void         check_empty_line(char **str, t_piece *piece)
{
    if (ft_strlen(*str))
    {
        piece->coords[0] = create_vector_from_coords(-2, -2);
        free(*str);
    }
}
void		vector_from_piece(t_vector c, t_vector *first_point,
		int *points, t_piece *curr)
{
	t_vector	coords;

	if (!(++(*points)))
	{
		*first_point = create_vector_from_coords(c.x, c.y);
		coords = create_vector_from_coords(0, 0);
	}
	else if (*points < 4)
		coords = create_vector_from_coords(c.x - first_point->x,
				c.y - first_point->y);
    if (*points < 4)
	    curr->coords[*points] = coords;
    else
        curr->coords[0] = create_vector_from_coords(-2, -2);
}

void		print_piece(t_piece piece)
{
	int i;

	i = -1;
	while (++i < 4)
		printf("%d %d\n", piece.coords[i].x, piece.coords[i].y);
	printf("\n");
}

t_piece		read_piece(int fd, char **str)
{
	t_piece		curr;
	t_vector	first_point;
	t_vector	iters;
	t_vector	pts_ret;
	char		*line;

	iters.x = -1;
	pts_ret.x = -1;
	while (++iters.x < 4 && ((iters.y = -1) == -1))
	{
		if (!(pts_ret.y = gnl(fd, &line)))
			curr.coords[0] = create_vector_from_coords(-1, -1);
		else
		{
            *str = ft_strdup(line);
			if (check_full_line(line, &curr))
				while (++iters.y < 4)
					if (line[iters.y] == '#')
						vector_from_piece(create_vector_from_coords(iters.y,
									iters.x), &first_point, &pts_ret.x, &curr);
		}
		if (pts_ret.y)
			free(line);
	}
    if (gnl(fd, &line))
    {
        *str = ft_strcat(ft_strdup(line), "\n");
        check_empty_line(&line, &curr);
    }
    printf("STR = %s.\n", *str);
	return (curr);
}

void		delete_list(t_set **head)
{
	t_set	*curr;
	t_set	*tmp;

	curr = *head;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*head = NULL;
}

t_set		*create_list(int fd)
{
	t_set	*head;
	t_set	*iter;
	t_piece	figurka;
	char	*str;

	if (!(head = (t_set*)malloc(sizeof(*head))))
		return (NULL);
	head->prev = NULL;
	iter = head;
	figurka = read_piece(fd, &str);
	while (!(figurka.coords[0].x == -1 && figurka.coords[0].y == -1))
	{
        if (figurka.coords[0].x == -2 && figurka.coords[0].y == -2)
        {
            delete_list(&head);
            return (NULL);
        }
		iter->tet = figurka;
		if (!(iter->next = (t_set*)malloc(sizeof(*iter->next))))
			return (NULL);
		iter->next->prev = iter;
		iter = iter->next;
		figurka = read_piece(fd, &str);
	}
	iter->prev->next = NULL;
	free(iter);
    if (ft_strlen(str) != 4)
            delete_list(&head);
    free(str);
	return (head);
}

int         file_valid(int fd, t_set **lst)
{
    *lst = create_list(fd);
    printf("%p\n", *lst);
    if (*lst)
        return (1);
    else
        return (0);
}