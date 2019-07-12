/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:04:01 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/26 22:34:41 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "mylib.h"

void	ft_prerrs(char *str)
{
	extern int	errno;
	int			errnum;

	write(2, "cat: ", 5);
	write(2, str, ft_strlen(str));
	errnum = errno;
	if (errnum == EISDIR)
		write(2, ": Is a directory\n", 17);
	else if (errnum == ENOENT)
		write(2, ": No such file or directory\n", 28);
	else if (errnum == EACCES)
		write(2, ": Permission denied\n", 20);
}

void	ft_rp(int in, int out, int wrap)
{
	char	buf[25];
	int		ret;

	while ((ret = read(in, buf, 25)) != 0)
		write(out, buf, ret);
	if (wrap)
		write(out, "\n", 1);
}

void	ft_prfiles(int ac, char **av)
{
	int	fd;
	int	i;

	i = 0;
	while (++i <= ac)
	{
		if (!ft_strcmp(av[i], "-"))
			ft_rp(0, 1, 0);
		else if ((fd = open(av[i], O_RDWR)) == -1)
			ft_prerrs(av[i]);
		else
		{
			ft_rp(fd, 1, 0);
			if (close(fd) == -1)
				ft_prerrs(av[i]);
		}
	}
}

int		main(int argc, char **argv)
{
	char	c;

	if (argc == 1)
		while (read(STDIN_FILENO, &c, 1) > 0)
			write(1, &c, 1);
	else
		ft_prfiles(argc - 1, argv);
	return (0);
}
