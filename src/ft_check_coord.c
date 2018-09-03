/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:55:19 by cpaquet           #+#    #+#             */
/*   Updated: 2018/04/24 09:29:14 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ROOM ((t_coord*)room->content)
#define TMP ((t_coord*)tmp->content)

static int		ft_check_startend(t_list *room)
{
	char	start_nb;
	char	end_nb;

	start_nb = 'A';
	end_nb = 'A';
	while (room)
	{
		if (ROOM->position == 1)
			start_nb++;
		else if (ROOM->position == 2)
			end_nb++;
		room = room->next;
	}
	if (start_nb != 'B' || end_nb != 'B')
		return (-1);
	return (1);
}

int				check_roomcoord(t_list *room, t_coord *coord, char *name)
{
	while (room)
	{
		if (ft_strequ(ROOM->room_name, name) == 0 &&
				ROOM->x == coord->x && ROOM->y == coord->y)
			return (-1);
		room = room->next;
	}
	return (1);
}

int				check_link_start_end(t_coord *start)
{
	int		a;
	int		count;

	a = 0;
	count = 0;
	while (a < start->nbr_sons)
	{
		count += start->sons[a]->distance;
		a++;
	}
	if (count == 0)
		return (-1);
	return (1);
}

int				ft_check_coord(t_data *data)
{
	t_list	*tmp;
	char	*tmp_line;

	tmp = data->head_rooms;
	if (ft_check_startend(data->head_rooms) == -1)
		return (-1);
	while (tmp)
	{
		tmp_line = TMP->room_name;
		while (*tmp_line == ' ')
			tmp_line++;
		if (*tmp_line == 'L')
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
