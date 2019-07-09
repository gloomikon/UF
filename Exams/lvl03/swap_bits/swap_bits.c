/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:29:32 by exam              #+#    #+#             */
/*   Updated: 2019/02/12 11:10:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				pow2(int n)
{
	int i;

	i = 1;
	while (n)
	{
		i = i * 2;
		n--;
	}
	return (i);
}

unsigned char	swap_bits(unsigned char octet)
{
	int in[8];
	int	i;
	int	oc;
	int	d;

	i = -1;
	while (++i < 8)
		in[i] = 0;
	oc = octet;
	i = 3;
	while (oc)
	{
		in[i] = oc % 2;
		oc = oc / 2;
		i--;
		if (i < 0)
			i = 7;
	}
	i = 8;
	d = 0;
	while (--i >= 0)
		d += in[i] * pow2(7 - i);
	return (d);
}
