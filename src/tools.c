/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:45:40 by cpaquet           #+#    #+#             */
/*   Updated: 2018/04/23 19:27:41 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define SOL ((t_ant*)solution->content)

int			search_start_end(t_data *data)
{
	t_list	*tmp_rooms;

	tmp_rooms = data->head_rooms;
	while (THR->position != 1)
		tmp_rooms = tmp_rooms->next;
	data->start_rooms = THR;
	tmp_rooms = data->head_rooms;
	while (THR->position != 2)
		tmp_rooms = tmp_rooms->next;
	data->end_rooms = THR;
	if (data->start_rooms == NULL || data->end_rooms == NULL)
		return (0);
	return (1);
}

int			exclusive(char **path1, char **path2)
{
	int		index;
	int		index2;

	index = 1;
	if (!path2 || !path1)
		return (1);
	while (path1[index + 1])
	{
		index2 = 0;
		while (path2[index2 + 1])
		{
			if (ft_strequ(path1[index], path2[index2]) == 1)
				return (0);
			index2++;
		}
		index++;
	}
	return (1);
}

int			check_duplicate(t_ant *ant, t_list *solution)
{
	int		index;

	while (solution)
	{
		index = 0;
		while (ant->path[index])
		{
			if (ft_strequ(ant->path[index], SOL->path[index]) == 0)
				break ;
			index++;
		}
		if (ant->path[index] == NULL)
			break ;
		solution = solution->next;
	}
	if (solution != NULL)
		return (0);
	return (1);
}

void		ft_sort_index(t_coord *room)
{
	int			index;
	t_coord		*tmp;

	index = 0;
	while (index < room->nbr_sons - 1)
	{
		if (room->sons[index]->distance > room->sons[index + 1]->distance)
		{
			tmp = room->sons[index];
			room->sons[index] = room->sons[index + 1];
			room->sons[index + 1] = tmp;
			index = 0;
		}
		else
			index++;
	}
}

void		ft_sort_sol(t_sol *sol)
{
	int			index;
	t_ant		*tmp;

	index = 0;
	while (index < sol->nbr_path - 1)
	{
		if (sol->ant[index]->length > sol->ant[index + 1]->length)
		{
			tmp = sol->ant[index];
			sol->ant[index] = sol->ant[index + 1];
			sol->ant[index + 1] = tmp;
			index = 0;
		}
		else
			index++;
	}
}
