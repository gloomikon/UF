/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:51:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/02/16 12:51:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_set		*final_action(t_set **head, t_set **iter)
{
	if (*iter != *head)
	{
		(*iter)->prev->next = NULL;
		free(*iter);
		return (*head);
	}
	return (clear_and_return(head));
}
