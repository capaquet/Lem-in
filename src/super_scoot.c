/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_scoot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:01:55 by achirat           #+#    #+#             */
/*   Updated: 2018/05/07 18:54:02 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ANTCONT ((t_ant*)ant_new->content)

static void		ft_save_ant(t_data *data, t_list *ant_new)
{
	if (data->max_cost == 0)
		data->max_cost = data->ants_nbr + ANTCONT->length - 1;
	if (data->flag_path == 1)
		ft_print_path(ANTCONT);
	ft_lstaddend(&data->ant_sol, ant_new);
	combinatoire(data, ANTCONT);
}

static void		ft_create_ant(t_data *data, t_ant *ant, t_coord *room)
{
	t_list	*ant_new;
	int		index_path;

	index_path = 0;
	if (!(ant_new = ft_lstnew(ant, sizeof(t_ant))))
		exit(EXIT_FAILURE);
	ANTCONT->room = room;
	ANTCONT->length = ant->length + 1;
	ANTCONT->id = ++data->len_ant_list;
	if (!(ANTCONT->path = (char**)malloc(sizeof(char*) *
					(ANTCONT->length + 1))))
		exit(EXIT_FAILURE);
	while (index_path < ant->length)
	{
		ANTCONT->path[index_path] = ft_strdup(ant->path[index_path]);
		index_path++;
	}
	ANTCONT->path[ANTCONT->length - 1] = ft_strdup(room->room_name);
	ANTCONT->path[ANTCONT->length] = 0;
	if (ANTCONT->room->position == 2)
		ft_save_ant(data, ant_new);
	else
		ft_lstaddend(&data->ant_list, ant_new);
}

static void		ft_move(t_data *data, t_ant *ant)
{
	int		index_sons;

	index_sons = 0;
	while (index_sons < ant->room->nbr_sons)
	{
		if (ant->room->sons[index_sons]->distance < ant->room->distance)
			if (ft_not_visited(ant, ant->room->sons[index_sons]) == 1)
				ft_create_ant(data, ant, ant->room->sons[index_sons]);
		index_sons++;
	}
	return ;
}

static int		ft_ant(t_data *data)
{
	t_list		*ant;

	ant = data->ant_list;
	while (ant)
	{
		if (data->max_cost > 0 && ((t_ant*)ant->content)->length >
				data->max_cost)
			return (0);
		ft_move(data, ant->content);
		ant = ft_delete_ant(&data->ant_list, ant, 1);
	}
	return (1);
}

int				super_scoot(t_data *data)
{
	t_list		*room_list;

	room_list = data->head_rooms;
	ft_distance(data->end_rooms);
	if (check_link_start_end(data->start_rooms) == -1)
		return (-1);
	data->start_rooms->distance = data->rooms_nbrs;
	data->end_rooms->distance = 0;
	while (room_list)
	{
		ft_sort_index(room_list->content);
		room_list = room_list->next;
	}
	ft_create_first_ant(data);
	while (data->ant_list)
	{
		if (ft_ant(data) == 0)
			break ;
	}
	while (data->ant_list)
		data->ant_list = ft_delete_ant(&data->ant_list, data->ant_list, 1);
	if (data->ant_sol == NULL)
		return (-1);
	return (1);
}
