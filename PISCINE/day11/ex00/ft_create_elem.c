/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:12:51 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 21:27:30 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	list->data = data;
	list->next = NULL;
	return (list);
}
