/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:03:14 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/18 15:03:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = argc;
		while (--i >= 1)
		{
			j = -1;
			while (argv[i][++j] != '\0')
				ft_putchar(argv[i][j]);
			ft_putchar('\n');
		}
	}
	return (0);
}
