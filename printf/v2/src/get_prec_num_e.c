/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec_num_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:16:38 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 12:16:38 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	get_prec_num_e(long double d, int prec)
{
	int	neg;
	int	i;

	neg = (d >= 0 ? 1 : -1);
	d = d * neg;
	while (d >= 10)
		d /= 10;
	while (d < 1)
		d *= 10;
	i = -1;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}
