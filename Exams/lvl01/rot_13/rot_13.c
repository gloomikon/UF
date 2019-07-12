/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:12:45 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 10:25:01 by exam             ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = -1;
		while (argv[1][++i])
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = (char)((((int)argv[1][i] - 97 + 13) % 26) + 97);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = (char)((((int)argv[1][i] - 65 + 13) % 26) + 65);
		ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
