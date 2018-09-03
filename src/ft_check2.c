/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 08:52:23 by achirat           #+#    #+#             */
/*   Updated: 2018/05/07 17:39:07 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ROOM ((t_coord*)room->content)

int			check_room_dup(t_list *room, t_coord *new, char *name)
{
	while (room)
	{
		if (ROOM->x == new->x && ROOM->y == new->y &&
			(ft_strequ(ROOM->room_name, name)))
			return (-1);
		room = room->next;
	}
	return (0);
}

int			check_data(t_data *data)
{
	if (data->rooms_nbrs == 0 || data->ants_nbr <= 0)
		return (-1);
	else if (data->head_tubes == NULL)
		return (-1);
	return (0);
}

int			check_line_info(char *line)
{
	while (*line)
	{
		if (ft_isalpha(*line) == 1)
			return (0);
		line++;
	}
	return (1);
}

int			check_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	else
		return (-1);
}
