/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:47:40 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 18:47:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_str(t_pf_env *e)
{
	char	*tmp;

	if (e->flag.prec >= 0 && e->flag.prec < ft_strlen(e->out))
	{
		tmp = ft_strsub(e->out, 0, e->flag.prec);
		free(e->out);
		e->out = tmp;
	}
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_str_width(e);
	}
	else
	{
		print_str_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
