/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:35:35 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/27 22:29:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	if (!(btree = malloc(sizeof(t_btree))))
		return (NULL);
	btree->item = item;
	btree->left = 0;
	btree->right = 0;
	return (btree);
}
