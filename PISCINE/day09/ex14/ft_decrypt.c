/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:41:37 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/20 08:41:39 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_perso.h"

int		ft_atoi(char *str)
{
	int		is_neg;
	int		i;
	long	res;

	res = 0;
	i = 0;
	is_neg = 0;
	if (str[i] == '-')
	{
		is_neg = 1;
		i++;
	}
	if (str[0] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (is_neg)
		res = -res;
	return (res);
}

int		words_c(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '|' && str[i] != ';')
			if (str[i] != '\0')
				i++;
			else
				break ;
		while (str[i] == '|' || str[i] == ';')
			i++;
		res++;
	}
	return (res);
}

char	*words(char *str, int *index)
{
	int		i;
	int		n;
	char	*res;
	int		len;

	n = *index;
	i = n;
	while (str[i] != '|' && str[i] != ';' && str[i] != '\0')
		i++;
	len = i;
	while (str[i] == '|' || str[i] == ';')
		i++;
	*index = i;
	i = -1;
	res = (char*)malloc(sizeof(char) * (len - n + 1));
	while (++i < len - n)
		res[i] = str[n + i];
	res[i] = '\0';
	return (res);
}

char	**split_word(char *str, int *w_count)
{
	char	**res;
	int		i;
	int		index;

	*w_count = words_c(str);
	res = (char**)malloc(sizeof(char*) * (*w_count + 1));
	i = 0;
	index = 0;
	while (str[i] != '\0')
		res[index++] = words(str, &i);
	res[index] = 0;
	return (res);
}

t_perso	**ft_decrypt(char *str)
{
	char	**words;
	int		i;
	int		w_count;
	t_perso	**res;

	words = split_word(str, &w_count);
	res = (t_perso**)malloc(sizeof(t_perso*) * (w_count + 1));
	i = 0;
	while (*words)
	{
		res[i / 2] = (t_perso*)malloc(sizeof(t_perso));
		res[i / 2]->age = ft_atoi(*words++);
		res[i / 2]->name = *words++;
		i += 2;
	}
	return (res);
}
