/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:31:59 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 22:50:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
