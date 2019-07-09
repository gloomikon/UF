/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 06:07:41 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/20 06:07:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define OPEN 1
# define CLOSE 0
# define EXIT_SUCCESS 0

typedef int	t_ft_bool;

typedef struct	s_door
{
	int	state;
}				t_door;

t_ft_bool		open_door(t_door *door);
t_ft_bool		close_door(t_door *door);
t_ft_bool		is_door_open(t_door *door);
t_ft_bool		is_door_close(t_door *door);
#endif
