/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:27:58 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/22 15:41:41 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] == '.' || (str[i] >= '1' && str[i] <= '9')))
			return (0);
	}
	return (i);
}

int		ft_read_params(int argc, char **argv, int field[9][9])
{
	int i;
	int j;

	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (!ft_strlen(argv[i]) || ft_strlen(argv[i]) > 9)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		while (++j < 9)
			if (argv[i][j] == '.')
				field[i - 1][j] = 0;
			else if (argv[i][j] >= '1' && argv[i][j] <= '9')
				field[i - 1][j] = argv[i][j] - 48;
	}
	return (1);
}
