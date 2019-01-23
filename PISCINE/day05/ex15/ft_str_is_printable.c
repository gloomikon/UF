/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:23:10 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/17 16:28:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_printable(char c)
{
	if ((int)c <= 31)
		return (0);
	else
		return (1);
}

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
