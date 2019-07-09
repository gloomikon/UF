/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_endl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:48:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:48:05 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_endl(int fd)
{
	char	*buf;
	int		ret;
	int		c;
	int		i;

	if (fd < 0 || BUFF_SIZE <= 0 || !(buf = (char*)malloc(BUFF_SIZE + 1)))
		return (0);
	c = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = -1;
		buf[ret] = '\0';
		while (++i < ret)
			if (buf[i] == '\n')
				c++;
	}
	free(buf);
	return (!((c + 1) % 5));
}
