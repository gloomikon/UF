/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:55:29 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 13:27:47 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	char	*output;

	if (argc == 1)
		return ("");
	i = 0;
	len = 0;
	while (++i < argc)
		len += str_len(argv[i]);
	output = (char*)malloc(len + argc - 1);
	i = 0;
	len = -1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			output[++len] = argv[i][j];
		output[++len] = '\n';
	}
	output[++len] = '\0';
	return (output);
}
