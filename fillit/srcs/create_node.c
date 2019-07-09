/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:49:42 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:49:44 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_set	*create_node(t_set *prev)
{
	t_set *node;

	MALLCHECK((node = (t_set*)malloc(sizeof(*node))));
	node->next = NULL;
	node->prev = prev;
	return (node);
}
