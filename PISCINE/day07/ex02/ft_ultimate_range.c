/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:47:38 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 11:51:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int	*array;

	if (min >= max)
	{
		*range = (void*)0;
		return (0);
	}
	array = (int*)malloc((max - min) * 4);
	i = -1;
	while (min++ < max)
		array[++i] = min - 1;
	*range = array;
	return (i);
}
