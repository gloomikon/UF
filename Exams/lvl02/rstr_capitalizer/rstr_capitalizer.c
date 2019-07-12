/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:12:29 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 11:35:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int		letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

void	print(char **str)
{
	int	i;
	int	space;

	i = -1;
	space = 1;
	while ((*str)[++i])
		if (letter((*str)[i]) == 2)
			(*str)[i] = (*str)[i] + 32;
	while (--i >= 0)
		if ((*str)[i] == ' ' || (*str)[i] == '\t')
			space = 1;
		else if (letter((*str)[i]))
		{
			if (space)
				(*str)[i] = (*str)[i] - 32;
			space = 0;
		}
		else
			space = 0;
	ft_putstr(*str);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 0;
		while (++i < argc)
		{
			print(&argv[i]);
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
