/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:01:11 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/24 15:21:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *array;
	int i;

	if (array = (int*)malloc(sizeof(int) * length) == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		array[i] = f(tab[i]);
	return (array);
}
