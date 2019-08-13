/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:07:30 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/12 15:17:25 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_args(int argc, char **argv, t_lemin *lemin)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 2
		&& argv[i][0] == '-'
		&& ft_strchr(PROGRAM_FLAGS, argv[i][1]))
		{
			!ft_strcmp(argv[i], "-i") ? lemin->beauty |= INPUT : 0;
			!ft_strcmp(argv[i], "-r") ? lemin->beauty |= RESULT : 0;
			!ft_strcmp(argv[i], "-c") ? lemin->beauty |= COLOR : 0;
			!ft_strcmp(argv[i], "-p") ? lemin->beauty |= PATHS : 0;
			!ft_strcmp(argv[i], "-e") ? lemin->beauty |= EMOJI : 0;
			!ft_strcmp(argv[i], "-l") ? lemin->beauty |= LEAKS : 0;
			!ft_strcmp(argv[i], "-h") ? lemin->beauty |= HELP : 0;
		}
		else
			err_exit(lemin->beauty & LEAKS);
	}
}

int		main(int argc, char **argv)
{
	t_lemin	lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	read_args(argc, argv, &lemin);
	if (lemin.beauty & HELP)
		print_help();
	else
	{
		read_data(&lemin);
		main_algo(&lemin);
		(lemin.beauty & INPUT) ? 0 : print_input(&lemin);
		(lemin.beauty & PATHS) ? print_paths(&lemin) : 0;
		go_through_routes(&lemin);
		(lemin.beauty & RESULT) ? print_result(&lemin) : 0;
		(lemin.beauty & LEAKS) ? system("leaks -q lem_in") : 0;
	}
	return (0);
}
