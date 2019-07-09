/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:49:19 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/20 13:45:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	sort(int *tab, int length)
{
	int i;
	int j;
	int temp;

	i = length;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tab[j];
			}
	}
}

int		ft_unmatch(int *tab, int length)
{
	int i;
	int now;

	if (length ==
	sort(tab, length);
	now = arr[0];
	while (i < length)
	{
		while (arr[i]
		return (i);
}

int main()
{
	int arr[9] = {1, 1, 2, 4, 3, 4, 3, 4, 2, 3 ,4};
	printf("%d", ft_unmatch(arr, 7));
	return 0;
}
