/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:37:59 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 11:29:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	new_str = (char*)malloc(i + 1);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
