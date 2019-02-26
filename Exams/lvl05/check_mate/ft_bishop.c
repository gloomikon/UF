/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bishop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:40:55 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:11:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	ft_bishop(char **board, int x, int y, int size)
{
	return (ft_check_lu(board, x, y) ||
			ft_check_ld(board, x, y, size) ||
			ft_check_ru(board, x, y, size) ||
			ft_check_rd(board, x, y, size));
}
