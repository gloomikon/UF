/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wstr_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:30:44 by marvin            #+#    #+#             */
/*   Updated: 2019/06/25 14:30:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}
