/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:50:58 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:51:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_list(t_set **head)
{
	t_set	*current;
	t_set	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = current->next;
	}
	*head = NULL;
}
