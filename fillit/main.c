/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:40:12 by mzhurba           #+#    #+#             */
/*   Updated: 2019/01/24 12:40:17 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int main(int argc, char **argv)
{
    int fd;
    t_dlist *list;
    t_piece curr;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        list = ft_create_list(fd);
        while (list)
        {
            for (int i = 0; i < 4; i++)
                printf("%d %d \n", list->tet.coords[i].x, list->tet.coords[i].y);
                list = list->next;
        }
        return (0);
    }
    else
        return (-1);
}
