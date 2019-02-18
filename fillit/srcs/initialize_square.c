/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:32:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:12:44 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**initialize_square(int size)
{
	char	**sqr;
	int		j;

	sqr = (char **)malloc(sizeof(char*) * size + 1);
	j = 0;
	while (j < size)
	{
		*(sqr + j) = ft_strnew(size + 1);
		ft_memset((char *)*(sqr + j), (int)('.'), size);
		j++;
	}
	*(sqr + j) = NULL;
	return (sqr);
}
