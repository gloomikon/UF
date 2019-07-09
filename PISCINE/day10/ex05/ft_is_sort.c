/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:47:23 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/23 18:54:03 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ret;

	if (length <= 0)
		return (0);
	else if (length == 1)
		return (1);
	i = 0;
	while (f(tab[i], tab[i + 1]) == 0)
		i++;
	if (f(tab[i], tab[i + 1]) < 0)
		ret = 1;
	else
		ret = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0 && ret == -1)
			return (0);
		else if (f(tab[i], tab[i + 1]) && ret == 1)
			return (0);
	}
	return (1);
}
