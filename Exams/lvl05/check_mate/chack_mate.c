/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:00:35 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:35:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"
#include <stdlib.h>
#include <unistd.h>

int		is_piece(char c)
{
	return (c == 'K' || c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}

void	normalize(char **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size && (j = -1) == -1)
		while (++j < size)
			if (!is_piece(board[i][j]))
				board[i][j] = '.';
}

int		main(int argc, char **argv)
{
	int		size;
	char	**board;
	int		i;

	if (argc >= 2)
	{
		size = argc - 1;
		board = (char**)malloc(sizeof(char*) * size);
		i = -1;
		while (i++ < size)
			board[i] = argv[1 + i];
		normalize(board, size);
		if (check_board(board, size))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
		free(board);
	}
	write(1, "\n", 1);
	return (0);
}
