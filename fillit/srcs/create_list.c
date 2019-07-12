/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:50:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:50:11 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_set		*create_list(int fd)
{
	t_set	*head;
	t_set	*iter;
	t_piece	figurka;

	MALLCHECK((head = create_node(NULL)));
	iter = head;
	figurka = read_piece(fd);
	while (!(figurka.coords[0].x == -1 && figurka.coords[0].y == -1))
	{
		if ((figurka.coords[0].x == -2 && figurka.coords[0].y == -2))
			return (clear_and_return(&head));
		iter->tet = figurka;
		MALLCHECK((iter->next = create_node(iter)));
		iter = iter->next;
		figurka = read_piece(fd);
	}
	return (final_action(&head, &iter));
}
