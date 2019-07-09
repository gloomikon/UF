/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:50:12 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 13:02:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_brackets(char a, char b)
{
	return ((a == '(' && b == ')') ||
			(a == '{' && b == '}') ||
			(a == '[' && b == ']'));
}

int		check(char *str)
{
	char	stack[4097];
	int		i;
	int		k;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			stack[++k] = str[i];
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!check_brackets(stack[k--], str[i]))
				return (0);
	return (!k);
}

int		main(int argc, char **argv)
{
	int	i;

	if (argc >= 2)
	{
		i = 0;
		while (argv[++i])
			if (check(argv[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
	}
	else
		write(1, "\n", 1);
	return (0);
}
