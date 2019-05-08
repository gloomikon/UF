/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:42:24 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/08 20:07:53 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_tag(const char *restrict format, t_pf_env *e)
{
	int	i;
	int	tmp;

	init_flag(&e->flag);
	e->flag.f &= ~65408; //ПРЕПИСАТЬ
	e->tag.tag = 0;
	i = 0;
	if (IS_NUM(format[e->i]))
	{
		tmp = ft_atoi(format + e-> i);
		while (IS_NUM(format[e->i + i]))
			i++;
		if (format[e->i + i] == '$')
		{
			e->tag.tag = 1;
			e->tag.pos = tmp;
			e->i += i + 1;
		}
	}
}
