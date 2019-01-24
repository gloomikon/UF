/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:20:27 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/22 23:16:10 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_read_params(int argc, char **argv, int field[9][9]);
int		ft_check_field(int field[9][9]);
void	ft_putchar(char c);
int		ft_check_rows(int field[9][9]);
int		ft_check_cols(int field[9][9]);
int		ft_check_sqrs(int field[9][9]);

void	ft_print_sudoku(int field[9][9])
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < 9 && (j = -1) == -1)
	{
		while (++j < 8)
		{
			c = field[i][j] + '0';
			ft_putchar(c);
			ft_putchar(' ');
		}
		c = field[i][j] + '0';
		ft_putchar(c);
		ft_putchar('\n');
	}
}

void	recursive_check(int field[9][9])
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < 9 && (j = -1) == -1)
		while (++j < 9 && (k = 0) == 0)
			if (field[i][j] == 0)
				while (++k <= 9)
				{
					field[i][j] = k;
					if (ft_check_field(field) && i == 8 && j == 8)
					{
						ft_print_sudoku(field);
						return ;
					}
					else if (ft_check_field(field))
						recursive_check(field);
					else if (!ft_check_field(field) && k == 9)
					{
						field[i][j] = 0;
						return ;
					}
				}
}

int		main(int argc, char **argv)
{
	int field[9][9];

	if (!ft_read_params(argc, argv, field))
		return (0);
	recursive_check(field);
	return (0);
}
