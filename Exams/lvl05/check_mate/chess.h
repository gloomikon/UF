/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chess.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:36:19 by exam              #+#    #+#             */
/*   Updated: 2019/02/26 12:37:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHESS_H
# define CHESS_H

int	ft_check_left(char **board, int x, int y);
int	ft_check_up(char **board, int x, int y);
int	ft_check_right(char **board, int x, int y, int size);
int	ft_check_down(char **board, int x, int y, int size);
int	ft_check_lu(char **board, int x, int y);
int	ft_check_ld(char **board, int x, int y, int size);
int	ft_check_ru(char **board, int x, int y, int size);
int	ft_check_rd(char **board, int x, int y, int size);
int	ft_pawn(char **board, int x, int y, int size);
int	ft_bishop(char **board, int x, int y, int size);
int	ft_rook(char **board, int x, int y, int size);
int	ft_queen(char **board, int x, int y, int size);
int	check_board(char **board, int size);

#endif
