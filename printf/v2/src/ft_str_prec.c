/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:51:18 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 12:51:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_str_prec(char *s1, int dot, int end, int hash)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + 1);
	while (s1[++i] != '\0')
	{
		tmp[j++] = s1[i];
		if ((i == dot - 1 && end > 0) || hash)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i >= end)
		{
			tmp[j] = '\0';
			break ;
		}
	}
	return (tmp);
}
