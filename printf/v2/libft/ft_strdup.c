/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:51:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/24 16:50:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	int		a;
	char	*s2;

	a = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	ft_memcpy(s2, s1, a + 1);
	return (s2);
}
