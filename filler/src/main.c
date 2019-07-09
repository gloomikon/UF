/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:30:51 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/09 18:30:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main(void)
{
	t_filler	filler;
	
	ft_bzero(&filler, sizeof(t_filler));
	if (get_player(&filler))
		return (1);
	filler_loop(&filler);
	return (0);
}
