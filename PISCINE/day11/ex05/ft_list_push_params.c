/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:11:22 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/25 23:22:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	p_front(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = list;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*new;
	int		i;

	i = -1;
	new = 0;
	while (++i < ac)
		p_front(&new, av[i]);
	return (new);
}
