/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptraddr_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:12:11 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 16:12:11 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ptraddr_prec(t_pf_env *e)
{
	char	*tmp;
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = (int)ft_strlen(e->out);
	if (e->flag.prec > len)
	{
		tmp = ft_strnew(e->flag.prec - len);
		while (++i < e->flag.prec - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(e->out);
		free(tmp);
		e->out = res;
	}
	tmp = ft_strjoin("0x", e->out);
	free(e->out);
	e->out = tmp;
}
