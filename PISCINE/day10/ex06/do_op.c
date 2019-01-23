/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:21:20 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/24 17:05:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		(*g_arr[5])(int, int);

int		calculate(int x, int y, int op, int *res)
{
	if (y == 0 && op == 3)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	else if (y == 0 && op == 4)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	else
		*res = (g_arr[op])(x, y);
	return (1);
}

int		parse_operator(char *str)
{
	if (str[0] == '+' && str[1] == '\0')
		return (0);
	else if (str[0] == '-' && str[1] == '\0')
		return (1);
	else if (str[0] == '*' && str[1] == '\0')
		return (2);
	else if (str[0] == '/' && str[1] == '\0')
		return (3);
	else if (str[0] == '%' && str[1] == '\0')
		return (4);
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	int x;
	int y;
	int operator;
	int res;

	if (argc != 4)
		return (0);
	g_arr[0] = plus;
	g_arr[1] = minus;
	g_arr[2] = mul;
	g_arr[3] = div;
	g_arr[4] = mod;
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	if ((operator = parse_operator(argv[2])) < 0)
	{
		ft_putstr("0\n");
		return (0);
	}
	if (calculate(x, y, operator, &res))
	{
		ft_putnbr(res);
		ft_putstr("\n");
	}
	return (0);
}
