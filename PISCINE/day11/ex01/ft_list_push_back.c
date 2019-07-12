/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:27:40 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 22:45:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else if (!((*begin_list)->next))
		(*begin_list)->next = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}
