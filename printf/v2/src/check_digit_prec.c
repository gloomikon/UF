/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:19:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/06/19 17:26:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_digit_prec(t_pf_env *e)
{
	char *tmp;
	char *res;
	int len;
	int i;

	check_digit_sign(e);
	len = ft_strlen(e->out);
	if (e->flag.prec == 0 && e->out[0] == '0')
		e->out[0] = '\0';
	else if (e->flag.prec > len)
	{
		i = e->flag.prec - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(tmp);
		free(e->out);
		e->out = res;
	}
}
