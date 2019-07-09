/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:24:14 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 22:35:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_delete(t_list *prev, t_list *current, void *data_ref, int (*cmp)())
{
	while (current)
	{
		if (!(cmp(current->data, data_ref)))
		{
			current = current->next;
			free(prev->next);
			prev->next = current;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *prev;
	t_list *current;

	if (!*begin_list)
		return ;
	current = *begin_list;
	while (current && !(cmp(current->data, data_ref)))
	{
		*begin_list = (*begin_list)->next;
		free(current);
		current = *begin_list;
	}
	prev = 0;
	if (current)
		prev = current;
	current = current->next;
	ft_delete(prev, current, data_ref, cmp);
}
