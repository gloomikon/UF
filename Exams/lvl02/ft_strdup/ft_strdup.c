/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:23:55 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 10:29:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	new = (char*)malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	return (new);
}
