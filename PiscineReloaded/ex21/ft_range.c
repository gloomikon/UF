/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:59:49 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/24 17:59:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int i;

	if (min >= max)
		return (NULL);
	array = (int*)malloc((max - min) * 4);
	i = -1;
	while (min++ < max)
		array[++i] = min - 1;
	return (array);
}
