/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:31:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/08 20:08:13 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_mod(const char *restrict format, t_pf_env *e)
{
	if (!(e->flag.f & 65280))
	{
		if (format[e->i] == 'h' && format[e->i + 1] != 'h' && (e->flag.f &

	}
}