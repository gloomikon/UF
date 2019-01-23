/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:32:51 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/24 17:05:39 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H
# include <unistd.h>

void	ft_putchar(char s);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		plus(int x, int y);
int		minus(int x, int y);
int		mul(int x, int y);
int		div(int x, int y);
int		mod(int x, int y);

#endif
