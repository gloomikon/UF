/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:08:56 by akondaur          #+#    #+#             */
/*   Updated: 2018/07/25 22:39:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *last;
	t_list *first;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	first = *begin_list;
	last = (*begin_list)->next;
	ft_list_reverse(&last);
	first->next->next = first;
	first->next = 0;
	(*begin_list) = last;
}
