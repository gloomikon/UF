/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:55:01 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/17 17:15:06 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_set	*pcs;
	char	**sqr;

	if (argc != 2)
		return (int_putstr("Usage : ./fillit <filename>\n", 0));
	if (check_endl(fd = open(*(argv + 1), O_RDONLY)))
	{
		close(fd);
		fd = open(*(argv + 1), O_RDONLY);
		if (!file_valid(fd, &pcs))
			return (int_putstr("error\n", fd));
		sqr = big_fit(square_root(4 * count_pieces(pcs)) + 1, pcs);
		ft_putarr(sqr);
		free_square(sqr);
		close(fd);
		delete_list(&pcs);
	}
	else
		return (int_putstr("error\n", fd));
	return (0);
}
