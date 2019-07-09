/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_fit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:43:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:12:07 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**big_fit(int size, t_set *pcs)
{
	t_vector		ptn;
	int				fit_ret;
	int				fill;
	t_set			*save;
	t_fit_argument	arg;

	arg.fill = &fill;
	arg.chain = 0;
	arg.square = initialize_square(size);
	save = pcs;
	fill = 0;
	ptn.x = 0;
	ptn.y = 0;
	fit_ret = fit(&ptn, &pcs, arg);
	if (fit_ret == 2)
	{
		while (fit_ret == 2)
			fit_ret = fit(&ptn, &pcs, arg);
	}
	if (fit_ret == 0)
	{
		free_square(arg.square);
		return (big_fit(size + 1, save));
	}
	return (arg.square);
}
