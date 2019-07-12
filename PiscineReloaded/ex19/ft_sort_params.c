/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:11:57 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/24 18:35:13 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*c;

	i = argc;
	while (i-- > 0)
	{
		j = 0;
		while (++j < i)
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				c = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = c;
			}
	}
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			ft_putchar(argv[i][j]);
		ft_putchar('\n');
	}
	return (0);
}
