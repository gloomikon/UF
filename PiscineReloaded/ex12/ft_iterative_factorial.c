/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:12:59 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/24 18:30:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;
	int i;

	result = 1;
	i = 0;
	if (nb <= 13 && nb >= 0)
	{
		while (++i <= nb)
			result *= i;
		return (result);
	}
	return (0);
}
