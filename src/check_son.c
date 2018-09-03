/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_son.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:55:42 by achirat           #+#    #+#             */
/*   Updated: 2018/04/24 09:24:35 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_malloc_ntree(int index, t_coord *room)
{
	int		a;

	a = 0;
	if (!(room->sons = (t_coord**)(malloc(sizeof(t_coord*) * index))))
		exit(EXIT_FAILURE);
	room->nbr_sons = index;
	while (a < index)
		room->sons[a++] = NULL;
}

static t_coord		*find_name(char *name, t_data *data)
{
	t_list	*tmp_rooms;

	tmp_rooms = ((t_list*)(data->head_rooms));
	while (tmp_rooms)
	{
		if (ft_strequ(THR->room_name, name) == 1)
			return (tmp_rooms->content);
		tmp_rooms = tmp_rooms->next;
	}
	return (0);
}

static void			fill_sons(t_data *data)
{
	t_list	*tmp_rooms;
	t_list	*tmp_tubes;
	int		index;

	tmp_rooms = ((t_list*)(data->head_rooms));
	while (tmp_rooms)
	{
		tmp_tubes = ((t_list*)(data->head_tubes));
		index = 0;
		while (index < THR->nbr_sons && tmp_tubes)
		{
			if (ft_strequ(THT->name_1, THR->room_name) == 1)
				THR->sons[index++] = find_name(THT->name_2, data);
			else if (ft_strequ(THT->name_2, THR->room_name) == 1)
				THR->sons[index++] = find_name(THT->name_1, data);
			tmp_tubes = tmp_tubes->next;
		}
		tmp_rooms = tmp_rooms->next;
	}
}

void				check_son(t_data *data)
{
	t_list	*tmp_rooms;
	t_list	*tmp_tubes;
	int		nbr_sons;

	tmp_rooms = ((t_list*)(data->head_rooms));
	while (tmp_rooms)
	{
		nbr_sons = 0;
		tmp_tubes = ((t_list*)(data->head_tubes));
		while (tmp_tubes)
		{
			if (ft_strequ(THT->name_1, THR->room_name) == 1 ||
				ft_strequ(THT->name_2, THR->room_name) == 1)
				if (find_name(THT->name_1, data) &&
					find_name(THT->name_2, data))
					nbr_sons++;
			tmp_tubes = tmp_tubes->next;
		}
		nbr_sons != 0 ? ft_malloc_ntree(nbr_sons, THR) : 0;
		tmp_rooms = tmp_rooms->next;
	}
	fill_sons(data);
	data->sol_nbr = data->start_rooms->nbr_sons > data->end_rooms->nbr_sons ?
		data->end_rooms->nbr_sons : data->start_rooms->nbr_sons;
}
