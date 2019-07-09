/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 20:52:25 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/13 20:52:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int		count;

	if (power < 0)
		return (0);
	if (power > 0)
	{
		count = nb * ft_recursive_power(nb, power - 1);
		return (count);
	}
	else
	{
		return (1);
	}
}
