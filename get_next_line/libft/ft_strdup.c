/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:51:20 by mzhurba           #+#    #+#             */
/*   Updated: 2018/11/08 17:14:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;
	size_t	l;

	new = (char*)malloc(ft_strlen(s) + 1);
	i = -1;
	l = ft_strlen(s);
	if (new)
	{
		while (++i < l)
			new[i] = s[i];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
