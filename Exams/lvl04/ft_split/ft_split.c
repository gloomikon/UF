/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:41:13 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 12:10:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		count_words(char *str)
{
	int i;
	int space;
	int	words;

	i = -1;
	space = 1;
	words = 0;
	while (str[++i])
		if (is_space(str[i]))
			space = 1;
		else
		{
			if (space)
				words++;
			space = 0;
		}
	return (words);
}

char	**ft_split(char *str)
{
	char	**words;
	int		i;
	int		k;
	int		w;

	words = (char**)malloc(sizeof(char*) * (count_words(str) + 1));
	words[count_words(str)] = NULL;
	w = -1;
	i = -1;
	while (str[++i])
		if (!is_space(str[i]) && (k = 0) == 0)
		{
			while (str[i + k] && !is_space(str[i + k]))
				k++;
			words[++w] = (char*)malloc(k);
			k = 0;
			while (str[i + k] && !is_space(str[i + k]))
			{
				words[w][k] = str[i + k];
				k++;
			}
			words[w][k] = '\0';
			i = i + k - 1;
		}
	return (words);
}
