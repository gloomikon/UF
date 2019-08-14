/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:31:44 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/11 15:07:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_string	*create_string(char *line)
{
	t_string	*string;

	string = (t_string*)malloc(sizeof(t_string));
	string->next = NULL;
	string->str = line;
	return (string);
}

void		strs_push_str(t_string **strs, t_string *str)
{
	t_string	*curr;

	if (strs && *strs)
	{
		curr = *strs;
		while (curr->next)
			curr = curr->next;
		curr->next = str;
	}
	else if (strs)
		*strs = str;
}

char		*read_line(t_lemin *lemin)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line))
		strs_push_str(&lemin->strs, create_string(line));
	return (line);
}
