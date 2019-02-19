/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:55:03 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 11:21:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*create_buf(void)
{
	int		i;
	char	*buf;

	buf = (char*)malloc(4096);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < 4096)
	{
		buf[i] = '\0';
		i++;
	}
	return (buf);
}

void	do_action(char *str, char **pointer, int *i)
{
	int	loop;

	if (str[*i] == '.')
		write(1, *pointer, 1);
	if (str[*i] == '[' && !**pointer)
	{
		loop = 1;
		while (loop)
		{
			(*i)++;
			(str[*i] == '[') ? loop++ : loop;
			(str[*i] == ']') ? loop-- : loop;
		}
	}
	if (str[*i] == ']' && **pointer)
	{
		loop = 1;
		while (loop)
		{
			(*i)--;
			(str[*i] == ']') ? loop++ : loop;
			(str[*i] == '[') ? loop-- : loop;
		}
	}
}

int		main(int argc, char **argv)
{
	char	*pointer;
	char	*buf;
	int		i;

	if (argc == 2)
	{
		i = 0;
		if (!(buf = create_buf()))
			return (-1);
		pointer = buf;
		while (argv[1][i])
		{
			(argv[1][i] == '>') ? pointer++ : pointer;
			(argv[1][i] == '<') ? pointer-- : pointer;
			(argv[1][i] == '+') ? (*pointer)++ : *pointer;
			(argv[1][i] == '-') ? (*pointer)-- : *pointer;
			do_action(argv[1], &pointer, &i);
			i++;
		}
		free(buf);
	}
	else
		write(1, "\n", 1);
	return (0);
}
