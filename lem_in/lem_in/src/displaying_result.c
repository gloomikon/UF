/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:18:46 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/20 19:11:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_one_line(t_lemin *lemin, int ant, char *room)
{
	lemin->beauty & EMOJI ? ft_printf("🐜") : ft_printf("L");
	ft_printf("%d-%s ", ant, room);
	return (1);
}

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
		(lemin->beauty & COLOR) && (ft_printf("{off}"));
		s = s->next;
	}
	ft_printf("\n");
}

void	print_comb(t_lemin *lemin)
{
	int i;
	int j;

	i = -1;
	(lemin->beauty & COLOR) && ft_printf("{yellow}");
	ft_printf("NUMBER OF PATHS = %d\n", lemin->comb->count);
	(lemin->beauty & COLOR) && ft_printf("{off}");
	while (++i < lemin->comb->count && (j = -1))
	{
		(lemin->beauty & COLOR) && ft_printf("{green}");
		ft_printf("Path #%d length = %d\n", i + 1,
				lemin->comb->paths_arr[i]->len);
		(lemin->beauty & COLOR) && ft_printf("{off}");
		while (++j <= lemin->comb->paths_arr[i]->len)
		{
			ft_printf("%s ",
					lemin->comb->paths_arr[i]->verts_arr[j]->name);
			if (j != lemin->comb->paths_arr[i]->len)
				(lemin->beauty & EMOJI) ? ft_printf("👉 ") : ft_printf("--> ");
			else
				ft_printf("\n");
		}
	}
	printf("\n");
}

void	print_result(t_lemin *lemin)
{
	ft_printf("\n     <=- RESULT -=>\n     |%5d turns |\n", lemin->result);
}

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
