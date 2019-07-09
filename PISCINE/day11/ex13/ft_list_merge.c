/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:35:18 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 21:35:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *end1;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	end1 = *begin_list1;
	while (end1->next)
		end1 = end1->next;
	end1->next = begin_list2;
}
