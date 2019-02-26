/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:55:02 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 11:03:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	l;

	l = 0;
	if (!begin_list)
		return (l);
	while (begin_list)
	{
		l++;
		begin_list = begin_list->next;
	}
	return (l);
}
