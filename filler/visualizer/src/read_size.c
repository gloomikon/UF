/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:34:36 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 19:41:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	read_size(char *line, t_visualizer *v)
{
	char	*tmp;

	tmp = ft_strchr(line, ' ') + 1;
	MY = ft_atoi(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	MX = ft_atoi(tmp);
	ft_strdel(&line);
}
