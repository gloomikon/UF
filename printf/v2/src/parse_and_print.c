/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <mzhurba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:40:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/01 16:57:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_and_print(const char *restrict format, t_pf_env *e)
{
	++e->i;
	get_tag(format, e);
	get_flag(format, e);
	get_spec(format, e);
}
