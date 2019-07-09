/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:14:48 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 15:14:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check(char *p)
{
	if (*p == 9 || *p == 32 || *p == 10 || *p == 11)
		return (1);
	return (0);
}

int			ft_strlen(char *str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0' && check(&str[counter]) == 0)
		counter++;
	return (counter);
}

int			count(char *str)
{
	char	*p;
	int		counter;

	p = str;
	counter = 0;
	while (*p != '\0')
	{
		if (check(p) == 1)
		{
			while (check(p) == 1 && *p != '\0')
				p++;
		}
		else
		{
			counter++;
			while (check(p) == 0 && *p != '\0')
				p++;
		}
	}
	return (counter);
}

char		**ft_split_whitespaces(char *str)
{
	char	*p;
	char	**res;
	int		nbstr;
	int		i;
	int		j;

	nbstr = count(str);
	i = -1;
	j = 0;
	res = (char **)malloc(nbstr * sizeof(char *));
	while (++i < nbstr)
	{
		p = (char *)malloc((ft_strlen(str) + 1) * sizeof(char *));
		while (check(str) == 1 && *str != '\0')
			str++;
		while (check(str) == 0 && *str != '\0')
			p[j++] = *(str++);
		p[j] = '\0';
		res[i] = p;
		j = 0;
	}
	res[nbstr] = 0;
	return (res);
}
