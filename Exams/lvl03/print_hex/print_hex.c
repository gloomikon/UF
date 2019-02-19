/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:32:47 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 10:51:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int n)
{
	char	buf[4096];
	int		i;
	int		pos;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	pos = 0;
	while (n)
	{
		i = n % 16;
		if (i < 10)
			buf[pos] = '0' + i;
		else
			buf[pos] = 'a' + i - 10;
		pos++;
		n = n / 16;
	}
	while (--pos >= 0)
		write(1, &buf[pos], 1);
}

int		ft_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = -1;
	while (str[++i])
		n = n * 10 + (str[i] - '0');
	return (n);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
