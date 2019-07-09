/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:12:57 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 12:33:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		length(int nbr)
{
	int l;

	l = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		l++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;

	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr == 0)
		return ("0");
	i = length(nbr);
	str = (char*)malloc(i + 1);
	str[i] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
