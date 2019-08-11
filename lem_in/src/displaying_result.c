/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:18:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 16:27:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_input(t_lemin *lemin)
{
	t_string	*s;

	s = lemin->strs;
	while (s)
	{
		((lemin->beauty & COLOR) && !ft_isnumber(s->str, 10)) ?
									ft_printf("{yellow}") : 0;
		((lemin->beauty & COLOR) && comment(s->str)) ?
									ft_printf("{cyan}") : 0;
		((lemin->beauty & COLOR) && command(s->str)) ?
									ft_printf("{magenta}") : 0;
		((lemin->beauty & COLOR) && room(s->str)) ?
									ft_printf("{green}") : 0;
		ft_printf("%s\n", s->str);
		ft_printf("{off}");
		s = s->next;
	}
	ft_printf("\n");
}

void	print_paths(t_lemin *lemin)
{
	t_edge	*curr;
	int		i;

	i = -1;
	while (++i < lemin->start->output_links && (curr = lemin->routes[i].start))
	{
		while (curr->end != lemin->end)
		{
			lemin->beauty & COLOR ? ft_printf("{green}") : 0;
			ft_printf("[%s]{off}", curr->start->name);
			lemin->beauty & EMOJI ? ft_printf(" 👉 ") : ft_printf(" --> ");
			curr = lookfor_edge(lemin, curr->end, START);
		}
		lemin->beauty & COLOR ? ft_printf("{red}") : 0;
		ft_printf("[%s]{off}\n", lemin->end->name);
	}
	ft_printf("\n");
}

void	print_result(t_lemin *lemin)
{
	ft_printf("\n     <=- RESULT -=>\n     |%5d turns |\n", lemin->result);
}
