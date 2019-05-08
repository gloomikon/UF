/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:40:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/05/08 18:02:39 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_conversion(const char *restrict format, t_pf_env *e)
{
	++e->i;
	get_tag(format, e);
	get_flag(format, e);
	get_spec(format, e);
}
