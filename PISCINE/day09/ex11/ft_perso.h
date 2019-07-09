/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 04:55:58 by mzhurba           #+#    #+#             */
/*   Updated: 2018/07/20 05:03:15 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_THE_WORLD "SAVE_THE_WORLD"

typedef	struct		s_perso
{
	char	*name;
	double	life;
	int		age;
	char	*profession;
}					t_perso;
#endif
