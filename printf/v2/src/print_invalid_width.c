/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:31:25 by marvin            #+#    #+#             */
/*   Updated: 2019/06/30 15:31:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_invalid_width(t_pf_env *e)
{
	while (e->flag.width-- > 1)
		e->ret += (e->flag.f & F_ZERO ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}
