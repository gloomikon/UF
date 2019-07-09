/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 07:00:18 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/20 07:15:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compact(char **tab, int length)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == 0)
		{
			length--;
			k = 0;
			while (tab[i + k + 1])
			{
				j = 0;
				while (tab[i + k + 1][j])
				{
					tab[i + k][j] = tab[i + k + 1][j];
					j++;
				}
				k++;
			}
		}
		i++;
	}
	return (length);
}
