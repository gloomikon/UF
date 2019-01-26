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
void ft_ddel(t_dlist **head);

int main(int argc, char **argv)
{
    int fd;
    t_dlist *list;
    t_dlist *iter;
    //t_piece piece;


    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        list = ft_create_list(fd);
        iter = list;
        while (iter)
        {
            ft_print_piece(iter->tet);
            iter = iter->next;
        }
        ft_ddel(&list);
        close(fd);
        return (0);
    }
    else
        return (-1);
}
