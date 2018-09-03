/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_scoot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:01:55 by achirat           #+#    #+#             */
/*   Updated: 2018/04/24 10:32:39 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define ANTCONT ((t_ant*)ant_new->content)

void	ft_distance(t_coord *room)
{
	t_list	*pile;
	t_list	*tmp;
	int		index;

	pile = ft_lstnew(room, sizeof(t_coord));
	while (pile)
	{
		room = pile->content;
		index = 0;
		while (index < room->nbr_sons)
		{
			if (room->sons[index]->distance == 0
					&& room->sons[index]->position != 1)
			{
				room->sons[index]->distance = room->distance + 1;
				tmp = ft_lstnew(room->sons[index], sizeof(t_coord));
				ft_lstaddend(&pile, tmp);
			}
			index++;
		}
		tmp = pile;
		pile = pile->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_print_path(t_ant *ant)
{
	int index_path;

	index_path = 0;
	while (ant->path[index_path])
		ft_printf("%4s ", ant->path[index_path++]);
	ft_printf("\n");
}

void	ft_create_first_ant(t_data *data)
{
	t_list	*ant_new;
	t_ant	ant;

	ant.room = data->start_rooms;
	ant.length = 1;
	ant.id = ++data->len_ant_list;
	if (!(ant_new = ft_lstnew(&ant, sizeof(t_ant))))
		exit(EXIT_FAILURE);
	if (!(ANTCONT->path = (char**)malloc(sizeof(char*) *
														(ANTCONT->length + 1))))
		exit(EXIT_FAILURE);
	ANTCONT->path[0] = ft_strdup(((t_coord*)data->start_rooms)->room_name);
	ANTCONT->path[1] = 0;
	ant_new->next = NULL;
	ft_lstaddend(&data->ant_list, ant_new);
}

int		ft_not_visited(t_ant *ant, t_coord *room)
{
	int		index_path;

	index_path = 0;
	while (index_path < ant->length)
	{
		if (ft_strequ(ant->path[index_path], room->room_name) == 1)
			return (0);
		index_path++;
	}
	return (1);
}
