/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:17:14 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 20:17:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_str_width(t_pf_env *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += (e->flag.f & F_ZERO ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}
