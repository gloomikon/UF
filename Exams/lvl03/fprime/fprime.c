/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:34:28 by exam              #+#    #+#             */
/*   Updated: 2019/02/05 11:39:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	print_prime(int nb)
{
	int i;

	if (nb == 1)
		printf("1");
	else
		while (nb != 1)
		{
			i = 2;
			while (nb % i != 0)
				i++;
			printf("%d", i);
			nb /= i;
			if (nb != 1)
				printf("*");
		}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_prime(atoi(argv[1]));
	printf("\n");
	return (0);
}
