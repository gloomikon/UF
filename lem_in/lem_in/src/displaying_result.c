/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:18:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/14 12:43:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	print_input(t_lemin *lemin)
// {
// 	t_string	*s;

// 	s = lemin->strs;
// 	while (s)
// 	{
// 		((lemin->beauty & COLOR) && !ft_isnumber(s->str, 10)) ?
// 									ft_printf("{yellow}") : 0;
// 		((lemin->beauty & COLOR) && comment(s->str)) ?
// 									ft_printf("{cyan}") : 0;
// 		((lemin->beauty & COLOR) && command(s->str)) ?
// 									ft_printf("{magenta}") : 0;
// 		((lemin->beauty & COLOR) && room(s->str)) ?
// 									ft_printf("{green}") : 0;
// 		ft_printf("%s\n", s->str);
// 		ft_printf("{off}");
// 		s = s->next;
// 	}
// 	ft_printf("\n");
// }

// void	print_paths(t_lemin *lemin)
// {
// 	t_edge	*curr;
// 	int		i;

// 	i = -1;
// 	while (++i < lemin->start->output_links && (curr = lemin->routes[i].start))
// 	{
// 		while (curr->end != lemin->end)
// 		{
// 			lemin->beauty & COLOR ? ft_printf("{green}") : 0;
// 			ft_printf("[%s]{off}", curr->start->name);
// 			lemin->beauty & EMOJI ? ft_printf(" 👉 ") : ft_printf(" --> ");
// 			curr = lookfor_edge(lemin, curr->end, START);
// 		}
// 		lemin->beauty & COLOR ? ft_printf("{green}") : 0;
// 		ft_printf("[%s]{off}", curr->start->name);
// 		lemin->beauty & EMOJI ? ft_printf(" 👉 ") : ft_printf(" --> ");
// 		lemin->beauty & COLOR ? ft_printf("{red}") : 0;
// 		ft_printf("[%s]{off}\n", lemin->end->name);
// 	}
// 	ft_printf("\n");
// }

// void	print_result(t_lemin *lemin)
// {
// 	ft_printf("\n     <=- RESULT -=>\n     |%5d turns |\n", lemin->result);
// }

void	print_help(void)
{
	ft_printf("Usage: ./lem_in [flags] [< file]\n");
	ft_printf("\nAvailable flags:\n");
	ft_printf("-h\t(help)\t\tDisplays usage\n");
	ft_printf("-i\t(input)\t\tDo not print input data\n");
	ft_printf("-c\t(color)\t\tMake output colored\n");
	ft_printf("-e\t(emoji)\t\tPrints emojis instead of letters\n");
	ft_printf("-p\t(paths)\t\tDisplays found paths in graph\n");
	ft_printf("-r\t(result)\tDisplays the number of lines\n");
	ft_printf("-l\t(leaks)\t\tDisplays leaks\n");
}
