/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:52:29 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 13:52:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ftoa_prec_f(t_pf_env *e, long double d)
{
	int		prec;
	char	*tmp;
	char	*nb;
	long	num;

	tmp = ft_ltoa((long)d);
	d == 0 ? --e->flag.prec : 0;
	prec = ft_strlen(tmp);
	num = get_prec_num_f(d, (e->flag.prec >= 0 ? e->flag.prec : 6));
	nb = (num == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	if (e->flag.prec == 0)
		e->out = (e->flag.f & F_HASH) ? ft_strjoin(tmp, ".") : ft_strdup(tmp);
	else
		e->out = ft_str_prec(nb, prec, e->flag.prec >= 0 ?
		prec + e->flag.prec : prec + 6, e->flag.f & F_HASH);
	free(nb);
	free(tmp);
}
