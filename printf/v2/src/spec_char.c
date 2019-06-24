/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:24:59 by marvin            #+#    #+#             */
/*   Updated: 2019/06/24 18:24:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.f & F_MINUS ? e->flag.f &= ~F_ZERO : 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			return (print_null_str(e));
		e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}
