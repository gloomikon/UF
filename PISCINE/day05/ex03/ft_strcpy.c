/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:41:42 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/17 22:42:28 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (++i < ft_strlen(src))
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
