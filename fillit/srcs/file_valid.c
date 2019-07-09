/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:28:04 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:51:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	file_valid(int fd, t_set **lst)
{
	if ((*lst = create_list(fd)))
	{
		if ((count_pieces(*lst)) > 26)
		{
			delete_list(lst);
			return (0);
		}
		return (1);
	}
	return (0);
}
