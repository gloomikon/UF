/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:15:29 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/17 20:15:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		proverka_s(char *str, int base)
{
	int		i;
	int		j;
	int		sign;

	i = 0;
	j = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i++])
	{
		proverka = 0;
		while (base[j++])
		{
			if (str[i] == ' ' || str[i] == '+'
					|| str[i] == '-' || str[i] == str[j])
			{
				check += 1;
				break ;
			}
			j++;
		}
		if (check == 0)
			return (0);
	}
	return (1);
}

int		proverka_b(char *base)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j++])
			if (base[i] == base[j])
				return (0);
		i++;
	}
	return (1);
}

int		atoi(char *str, char *base, int i)
{
	int		nb;
	int		j;

	nb = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				nb *= 10;
				nb += j;
				break ;
			}
			j++;
		}
	}
	return (nb);
}
