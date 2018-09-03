/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:52:07 by achirat           #+#    #+#             */
/*   Updated: 2018/05/08 11:04:50 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define DISCONT ((t_display*)tmp->content)

static void	init_display(int ant, char **path, t_list **ant_dis)
{
	t_display	new_dis;
	t_list		*new_list;

	new_dis.id = ant;
	new_dis.index = 1;
	new_dis.path = path;
	if (!(new_list = ft_lstnew(&new_dis, sizeof(t_display))))
		exit(EXIT_FAILURE);
	ft_lstaddend(ant_dis, new_list);
}

static void	ft_move(t_data *data)
{
	t_list	*tmp;

	tmp = data->ant_dis;
	while (tmp)
	{
		ft_printf("L%d-%s", DISCONT->id, DISCONT->path[DISCONT->index++]);
		if (tmp->next != NULL)
			ft_printf(" ");
		if (DISCONT->path[DISCONT->index] == NULL)
			tmp = delete_dis(data, tmp);
		else
			tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	launch(t_sol *sol, t_data *data)
{
	int		ant;
	int		index;

	ant = 1;
	while (ant <= data->ants_nbr)
	{
		index = 0;
		while (index < sol->nbr_path && ant <= data->ants_nbr)
		{
			if (data->ants_nbr - ant >= sol->ant[index]->length
					- sol->ant[0]->length)
			{
				init_display(ant, sol->ant[index]->path, &data->ant_dis);
				ant++;
			}
			index++;
		}
		ft_move(data);
	}
}

void		distribute(t_data *data)
{
	t_list	*tmp;

	tmp = data->solution_list;
	while (((t_sol*)tmp->content)->cost != data->max_cost)
		tmp = tmp->next;
	ft_sort_sol(tmp->content);
	launch(tmp->content, data);
	while (data->ant_dis)
		ft_move(data);
}
