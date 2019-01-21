/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:00:34 by mzhurba           #+#    #+#             */
/*   Updated: 2019/01/21 16:03:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	create_line(char **strings, char **line, int fd)
{
	char	*tmp;
	int		l;

	l = 0;
	while (strings[fd][l] != '\n' && strings[fd][l])
		l++;
	if (strings[fd][l] == '\n')
	{
		*line = ft_strsub(strings[fd], 0, l);
		tmp = ft_strdup(strings[fd] + l + 1);
		free(strings[fd]);
		strings[fd] = tmp;
		if (!strings[fd][0])
			ft_strdel(&strings[fd]);
	}
	else
	{
		*line = ft_strdup(strings[fd]);
		ft_strdel(&strings[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*strings[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!strings[fd])
			strings[fd] = ft_strnew(1);
		tmp = ft_strjoin(strings[fd], buf);
		free(strings[fd]);
		strings[fd] = tmp;
		if (ft_strchr(strings[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!strings[fd] || !strings[fd][0]))
		return (0);
	return (create_line(strings, line, fd));
}
