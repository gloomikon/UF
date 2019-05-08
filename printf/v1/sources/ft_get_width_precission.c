/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width_precission.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:21:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/07 18:10:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_get_width_precission(t_printf_struct *ps)
{
	if (IS_POS_NUM(*ps->format))
	{
		ps->min_length = MAX(1, ft_atoi(ps->format));
		while (IS_NUM(*ps->format))
			++ps->format;
	}
	if (*ps->format == '.')
	{
		++ps->format;
		ps->precission = ft_atoi(ps->format);
		if (ps->precission < 0)
		{
			ps->f |= FL_MINUS;
			ps->min_length = -ps->precission;
			ps->precission = 1;
			++ps->format;
		}
		while (IS_NUM(*ps->format))
			++ps->format;
		ps->f |= APP_PRECI;
	}
}