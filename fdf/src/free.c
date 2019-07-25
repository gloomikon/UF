/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:42:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/24 22:44:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split_array(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
}

void	free_lst(t_point_lst **lst)
{
	t_point_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->nxt;
		free(*lst);
		*lst = tmp;
	}
}
