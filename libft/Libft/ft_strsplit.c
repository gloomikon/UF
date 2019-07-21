/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:09:08 by mzhurba           #+#    #+#             */
/*   Updated: 2018/11/08 16:50:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t		words;
	char		*tmp;

	words = 0;
	tmp = (char*)s;
	while (*tmp)
	{
		if (*tmp != c && (*(tmp - 1) == c || (tmp - 1) < s))
			words++;
		tmp++;
	}
	return (words);
}

static int		ft_copy_str(char const *s, char c, size_t words,
				char **res)
{
	size_t	i;
	size_t	len_str;
	char	*ptr;

	i = 0;
	len_str = 0;
	ptr = (char*)s;
	while (i < words)
	{
		if (*ptr != c && *ptr)
			len_str++;
		else if (len_str)
		{
			if (!(res[i++] = ft_strndup((char*)(ptr - len_str), len_str)))
				return (1);
			len_str = 0;
		}
		ptr++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	if ((res = (char**)malloc(sizeof(char**) * (words + 1))) == NULL)
		return (NULL);
	if (ft_copy_str(s, c, words, res))
		return (NULL);
	res[words] = NULL;
	return (res);
}
