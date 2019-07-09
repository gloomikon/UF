/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 12:40:45 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/22 22:20:04 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_rows(int field[9][9])
{
	int i;
	int j;
	int k;
	int check[9];

	i = -1;
	while (++i < 9 && (k = -1) == -1)
	{
		while (++k < 9 && (j = -1) == -1)
			check[k] = 0;
		while (++j < 9)
			if (field[i][j] == 0)
				;
			else if (check[field[i][j] - 1] == 0)
				check[field[i][j] - 1] = 1;
			else
				return (0);
	}
	return (1);
}

int		ft_check_cols(int field[9][9])
{
	int i;
	int j;
	int k;
	int check[9];

	i = -1;
	while (++i < 9 && (k = -1) == -1)
	{
		while (++k < 9 && (j = -1) == -1)
			check[k] = 0;
		while (++j < 9)
			if (field[j][i] == 0)
				;
			else if (check[field[j][i] - 1] == 0)
				check[field[j][i] - 1] = 1;
			else
				return (0);
	}
	return (1);
}

int		ft_check_sqrs(int field[9][9])
{
	int i;
	int j;
	int k;
	int check[9];
	int s;

	s = -1;
	while (++s < 9 && (k = -1) == -1)
	{
		while (++k < 9 && (i = -1) == -1)
			check[k] = 0;
		while (++i < 3 && (j = -1) == -1)
		{
			while (++j < 3)
				if (field[i + (s / 3) * 3][j + (s % 3) * 3] == 0)
					;
				else if (check[field[i + (s / 3) * 3][j + (s % 3) * 3] - 1]
						== 0)
					check[field[i + (s / 3) * 3][j + (s % 3) * 3] - 1] = 1;
				else
					return (0);
		}
	}
	return (1);
}

int		ft_check_field(int field[9][9])
{
	return (ft_check_rows(field) &&
			ft_check_cols(field) &&
			ft_check_sqrs(field));
}
