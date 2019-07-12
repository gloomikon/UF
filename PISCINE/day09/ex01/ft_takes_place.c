/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:45:50 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/19 19:30:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int my_hour;

	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	my_hour = hour;
	if (hour > 12)
		my_hour = hour % 12;
	if (hour == 0)
		my_hour = 12;
	if (hour < 11)
		printf("%d.00. A.M. AND %d .00 A.M.\n", my_hour, (my_hour + 1) % 12);
	else if (hour == 11)
		printf("11.00 A.M. AND 12.00 P.M.\n");
	else if (hour == 23)
		printf("11.00 P.M. AND 12.00 A.M.\n");
	else if (hour == 24)
		printf("12.00 A.M. AND 1.00 A.M.\n");
	else
		printf("%d.00 P.M. AND %d.00 P.M.\n", my_hour, (my_hour + 1) % 12);
}
