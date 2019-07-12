/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:18:42 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:33:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	ft_rook(char **board, int x, int y, int size)
{
	return (ft_check_left(board, x, y) ||
			ft_check_up(board, x, y) ||
			ft_check_right(board, x, y, size) ||
			ft_check_down(board, x, y, size));
}
