#include "fillit.h"
#include <stdio.h>

void ft_ddel(t_dlist **head);

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

void ft_print_piece(t_piece piece)
{
    for (int i = 0; i < 4; i++)
        printf("%d %d\n", piece.coords[i].x, piece.coords[i].y);
    printf("\n");
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
        if (ret)
            free(line);
    }
    if ((ret = get_next_line(fd, &line)) == 1)
        free(line);
    return curr;    
}

t_dlist *ft_create_list(int fd)
{
    t_dlist *head;
    t_dlist *iter;
    t_piece figurka;

    if (!(head = (t_dlist*)malloc(sizeof(*head))))
        return (NULL);
    head->prev = NULL;
    // head->next = NULL;
    iter = head;
    figurka = ft_read_piece(fd);
    while (!(figurka.coords[0].x == -1 && figurka.coords[0].y == -1))
    {
        iter->tet = figurka;
        if (!(iter->next = (t_dlist*)malloc(sizeof(*iter->next))))
            return (NULL);
        iter->next->prev = iter;
        iter = iter->next;
        figurka = ft_read_piece(fd);
    }
    iter->prev->next = NULL;
    free(iter);
    return (head);
}

void ft_ddel(t_dlist **head)
{
    t_dlist *curr = *head;
    t_dlist *tmp;
    
    while (curr)
    {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}