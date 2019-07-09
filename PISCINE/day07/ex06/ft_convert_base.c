/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:41:21 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 22:41:28 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_result;

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (str[i])
	{
		if (i >= j)
			return (str);
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i++;
		j--;
	}
	return (str);
}

char	*ft_calc_in_base(int nb, int len_base, char *base_to, int signe)
{
	int i;

	i = 0;
	if (nb == 0)
	{
		g_result[0] = '0';
		g_result[1] = '\0';
		return (g_result);
	}
	i = 0;
	while (nb > 0)
	{
		g_result[i++] = base_to[nb % len_base];
		nb = nb / len_base;
	}
	if (signe == -1)
	{
		g_result[i] = '-';
		i++;
	}
	g_result[i] = '\0';
	ft_strrev(g_result);
	return (g_result);
}

void	ft_init_result(int nb, int len_base)
{
	int tmp;
	int i;

	i = 0;
	tmp = nb;
	while (tmp)
	{
		tmp = tmp / len_base;
		i++;
	}
	g_result = (char*)malloc(sizeof(g_result) * (i + 1));
}

int		ft_atoi_base(char *str, char *base, int len_base)
{
	int number;
	int j;

	j = 0;
	if (*str == '-' || *str == '+')
		str++;
	number = 0;
	while (*str != '\0')
	{
		number *= len_base;
		j = 0;
		while (*str != base[j])
			j++;
		number += j;
		str++;
	}
	ft_init_result(number, len_base);
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	int len_base_from;
	int len_base_to;
	int len_nbr;
	int signe;

	i = 0;
	len_nbr = 0;
	len_base_to = 0;
	len_base_from = 0;
	while (nbr[len_nbr])
		len_nbr++;
	while (base_to[len_base_to])
		len_base_to++;
	while (base_from[len_base_from])
		len_base_from++;
	if (nbr[i] == '-')
	{
		signe = -1;
		len_nbr--;
	}
	else
		signe = 1;
	return (ft_calc_in_base(ft_atoi_base(nbr, base_from, len_base_from),
				len_base_to, base_to, signe));
}
