/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:40:22 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 11:06:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_base = "0123456789ABCDEF";

char	*create_str(int p, int *i, int neg)
{
	char	*str;

	str = (char*)malloc(p + 2 + neg);
	str[p + 1] = '\0';
	if (neg)
	{
		str[0] = '-';
		*i = 0;
	}
	else
		*i = -1;
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	char	c[10000];
	int		p;
	char	*str;
	int		i;
	int		neg;

	p = -1;
	neg = 0;
	if (base == 10 && value < 0)
		neg = 1;
	if (value == 0)
		return ("0");
	while (value != 0)
	{
		i = value % base;
		if (i < 0)
			i *= -1;
		c[++p] = g_base[i];
		value = value / base;
	}
	str = create_str(p, &i, neg);
	while (p >= 0)
		str[++i] = c[p--];
	return (str);
}
