/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:38:33 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 14:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_wstr(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wstr_c(e, c);
	else if (c <= 0x7FF)
	{
		put_wstr_c(e, (c >> 6) + 0xC0);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wstr_c(e, ((c >> 12) + 0xE0));
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wstr_c(e, (c >> 18) + 0xF0);
		put_wstr_c(e, ((c >> 12) & 0x3F) + 0x80);
		put_wstr_c(e, ((c >> 6) & 0x3F) + 0x80);
		put_wstr_c(e, (c & 0x3F) + 0x80);
	}
}
