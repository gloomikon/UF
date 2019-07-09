/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:38:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/07 12:47:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_gnl
{
	char	*rests[INT_MAX];
	char	**curr;
	char	*buf;
}				t_gnl;

#endif
