/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:30:04 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/17 17:20:11 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fit(t_vector *ptn, t_set **pcs, t_fit_argument arg)
{
	t_vector nls;

	arg.chain++;
	if (*pcs == NULL)
		return (1);
	nls = next_legal_slot(*ptn, (*pcs)->tet, arg.square);
	if ((nls.x == -1 && ((*(arg.fill))) == 0) || arg.chain > 1000)
		return (arg.chain > 1000 ? 2 : 0);
	if (nls.x != -1)
	{
		put_piece(nls, (*pcs)->tet, arg.square, 'A' + ((*(arg.fill))));
		ptn->x = 0;
		ptn->y = 0;
		((*(arg.fill))) = ((*(arg.fill))) + 1;
		*(pcs) = (*pcs)->next;
		return (fit(ptn, pcs, arg));
	}
	else
	{
		(*pcs) = (*pcs)->prev;
		((*(arg.fill))) = ((*(arg.fill))) - 1;
		*ptn = erase_piece('A' + ((*(arg.fill))), (*pcs)->tet, arg.square);
		return (fit(ptn, pcs, arg));
	}
	return (0);
}
