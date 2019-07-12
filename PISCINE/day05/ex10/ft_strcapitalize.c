/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 22:13:35 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/17 09:58:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_letter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		big_letter;

	i = 0;
	big_letter = 1;
	while (str[i] != '\0')
	{
		if (is_letter(str[i]) || is_number(str[i]))
		{
			if (big_letter && is_letter(str[i]) == 1)
				str[i] -= 32;
			else if (!big_letter && is_letter(str[i]) == 2)
				str[i] += 32;
			big_letter = 0;
		}
		else
			big_letter = 1;
		i++;
	}
	return (str);
}
