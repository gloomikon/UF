/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:06:29 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:38:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	check_board(char **board, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = -1) == -1)
		while (++j < size)
		{
			if (board[i][j] == 'P' && ft_pawn(board, j, i, size))
				return (1);
			if (board[i][j] == 'B' && ft_bishop(board, j, i, size))
				return (1);
			if (board[i][j] == 'R' && ft_rook(board, j, i, size))
				return (1);
			if (board[i][j] == 'Q' && ft_queen(board, j, i, size))
				return (1);
		}
	return (0);
}
