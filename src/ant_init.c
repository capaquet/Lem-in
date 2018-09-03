/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:47:38 by cpaquet           #+#    #+#             */
/*   Updated: 2018/04/24 09:39:42 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define START_SONS ((t_coord*)data->start_rooms)->nbr_sons
#define END_SONS ((t_coord*)data->end_rooms)->nbr_sons

static t_list		*sol_init(t_ant *ant, int cost, int sol_nbr)
{
	t_list	*new_list;
	t_sol	*new_sol;
	int		index;

	index = 0;
	if (!(new_sol = (t_sol*)malloc(sizeof(t_sol))))
		exit(EXIT_FAILURE);
	new_sol->cost = cost;
	new_sol->nbr_path = sol_nbr;
	if (!(new_sol->ant = (t_ant**)malloc(sizeof(t_ant*) * sol_nbr)))
		exit(EXIT_FAILURE);
	while (index < sol_nbr)
		new_sol->ant[index++] = NULL;
	if (ant != 0)
		new_sol->ant[0] = ant;
	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		exit(EXIT_FAILURE);
	new_list->content = new_sol;
	new_list->content_size = sizeof(t_sol);
	new_list->next = NULL;
	return (new_list);
}

int					init_solution_list(t_data *data)
{
	t_list	*first_list;
	int		index;

	index = 1;
	data->sol_nbr = START_SONS > END_SONS ? END_SONS : START_SONS;
	if (data->max_cost == 0)
		data->max_cost = data->ants_nbr +
			((t_ant*)data->ant_sol->content)->length - 1;
	first_list = sol_init(((t_ant*)data->ant_sol->content),
			data->max_cost, index);
	ft_lstaddend(&data->solution_list, first_list);
	index++;
	while (index <= data->sol_nbr && index < 15)
	{
		ft_lstaddend(&data->solution_list,
		sol_init(0, (data->rooms_nbrs + data->ants_nbr), index));
		index++;
	}
	return (1);
}
