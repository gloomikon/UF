#include "fillit.h"

t_vector ft_create_vector_from_coords(int x, int y)
{
    t_vector    coords;
    coords.x = x;
    coords.y = y;
    return coords;
}

void ft_vector_for_piece(int x, int y, t_vector *firstPoint, int *points, t_piece *curr)
{
    t_vector coords;

    if (!(++(*points)))
    {
        *firstPoint = ft_create_vector_from_coords(x, y);
        coords = ft_create_vector_from_coords(0, 0);
    }
    else
        coords = ft_create_vector_from_coords(x - firstPoint->x, y - firstPoint->y);
    curr->coords[*points] = coords;
}

t_piece ft_read_piece(int fd)
{
    t_piece curr;
    t_vector firstPoint;
    int i;
    int j;
    int points;
    int ret;
    char *line;

    i = -1;
    points = -1;
    while (++i < 4 && ((j = -1) == -1))
    {    
        if (!(ret = get_next_line(fd, &line)))
            curr.coords[0] = ft_create_vector_from_coords(-1, -1);
        else
        {
            while  (++j < 4)
                if (line[j] == '#')
                    ft_vector_for_piece(j, i, &firstPoint, &points, &curr);
        }
    }
    free(line);
    return curr;    
}

t_dlist *ft_create_list(int fd)
{
    t_dlist *start;
    t_dlist *curr;
    t_dlist *prev;
    t_piece piece;

    start = (t_dlist*)malloc(sizeof(t_dlist*));
    curr = start;
    prev = NULL;
    piece = ft_read_piece(fd);
    while (!(piece.coords[0].x == -1 && piece.coords[0].y == -1))
    {
        curr->tet = piece;
        curr->prev = prev;
        curr->next = (t_dlist*)malloc(sizeof(t_dlist*));
        prev = curr;
        curr = curr->next;
        piece = ft_read_piece(fd);
    }
    return (start);
}