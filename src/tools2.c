/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:18:29 by cpaquet           #+#    #+#             */
/*   Updated: 2018/05/07 18:57:45 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*delete_dis(t_data *data, t_list *dis)
{
	t_list	*tmp;

	tmp = data->ant_dis;
	if (tmp == dis)
	{
		tmp = tmp->next;
		data->ant_dis = tmp;
	}
	else
	{
		while (tmp->next != dis)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	free(dis->content);
	free(dis);
	return (tmp);
}

t_list		*ft_delete_ant(t_list **list, t_list *ant, int flag)
{
	t_list	*tmp;

	if (*list == ant)
	{
		*list = (*list)->next;
		tmp = *list;
	}
	else
	{
		tmp = *list;
		while (tmp->next != ant)
			tmp = tmp->next;
		tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	if (flag == 1)
	{
		free_double_tab(&((t_ant *)ant->content)->path, 42);
		free(((t_ant*)ant->content)->path);
		free(((t_ant*)ant->content));
		free(ant);
	}
	return (tmp);
}

void		ft_free1(t_data *data)
{
	int		index;
	t_list	*tmp;

	while (data->head_tubes)
	{
		ft_strdel(&((t_tube*)data->head_tubes->content)->name_1);
		ft_strdel(&((t_tube*)data->head_tubes->content)->name_2);
		free(data->head_tubes->content);
		tmp = data->head_tubes;
		data->head_tubes = data->head_tubes->next;
		free(tmp);
	}
	while (data->head_rooms)
	{
		index = 0;
		free(((t_coord*)data->head_rooms->content)->sons);
		ft_strdel(&((t_coord*)data->head_rooms->content)->room_name);
		tmp = data->head_rooms;
		data->head_rooms = data->head_rooms->next;
		free(tmp->content);
		free(tmp);
	}
}

void		ft_free2(t_data *data)
{
	t_list	*tmp;
	int		a;

	a = 0;
	while (data->ant_sol)
		data->ant_sol = ft_delete_ant(&data->ant_sol, data->ant_sol, 1);
	while (data->solution_list)
	{
		tmp = data->solution_list;
		data->solution_list = data->solution_list->next;
		free(((t_sol*)tmp->content)->ant);
		free(tmp->content);
		free(tmp);
	}
	while (a < data->line_map)
		free(data->maps[a++]);
	free(data->maps);
}

int			free_double_tab(char ***tab, int c)
{
	int		a;

	a = 0;
	while ((*tab)[a])
	{
		free((*tab)[a]);
		a++;
	}
	free(*tab);
	*tab = NULL;
	return (c);
}
