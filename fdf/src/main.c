/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/23 18:34:41 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_exit(char *err)
{
	ft_printf("%s\n", err);
	system("leaks a.out");
	exit(1);
}

/*
**	VALIDATION
*/

int		ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

static int		ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_has_prefix(const char *str, int base)
{
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[0] != '0')
			return (0);
		if (base == 2 && (str[1] == 'b' || str[1] == 'B'))
			return (1);
		if (base == 16 && (str[1] == 'x' || str[1] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}

int				ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}

int			ft_isnumber(char *str, int base)
{
	size_t		i;
	size_t		digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? 1 : 0);
}

/*
**	FREE MEMORY
*/

void	free_split_array(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	free(split);
}

void	free_lst(t_point_lst **lst)
{
	t_point_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->nxt;
		free(*lst);
		*lst = tmp;
	}
}

/*
**	WORK WITH LIST
*/

void		lst_push(t_point_lst **coords_stack, t_point_lst *new)
{
	if (coords_stack)
	{
		if (new)
			new->nxt = *coords_stack;
		*coords_stack = new;
	}
	else
		*coords_stack = new;
}

static t_point_lst	*new_point(char *s, char **split, t_point_lst **lst)
{
	t_point_lst	*coord;
	char		**parts;

	coord = (t_point_lst *)ft_memalloc(sizeof(t_point_lst));
	parts = ft_strsplit(s, ',');
	if (!ft_isnumber(parts[0], 10))
	{
		free_split_array(split);
		free_split_array(parts);
		free_lst(lst);
		err_exit(ERR_MAP);
	}
	if (parts[1] && !ft_isnumber(parts[1], 16))
	{
		free_split_array(split);
		free_split_array(parts);
		free_lst(lst);
		err_exit(ERR_MAP);
	}
	coord->val.z = ft_atoi(parts[0]);
	coord->val.color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->nxt = NULL;
	free_split_array(parts);
	return (coord);
}

/*
** READING
*/

void	read_map(int fd, t_fdf *fdf)
{
	char		*line;
	char		**split;
	int			res;
	int			width;
	t_point_lst	*lst;

	lst = NULL;
	while (get_next_line(fd, &line) && !(width = 0) && (++fdf->map.height))
	{
		split = ft_strsplit(line, ' ');
		while (split[width])
			lst_push(&lst, new_point(split[width++], split, &lst));
		ft_strdel(&line);
		free_split_array(split);
		fdf->map.width = fdf->map.height == 1 ? width : fdf->map.width;
		if (fdf->map.width != width)
		{
			free_lst(&lst);
			err_exit(ERR_MAP);
		}
	}
	if (!(*split))
		err_exit(ERR_MAP);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		err_exit(ERR_USAGE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		err_exit(ERR_FILE);
	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(fd, &fdf);
}
