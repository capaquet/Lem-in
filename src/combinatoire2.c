/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinatoire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:01:15 by achirat           #+#    #+#             */
/*   Updated: 2018/04/20 12:07:26 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			verify_ant(t_ant **comb, t_ant *ant, int sol_nbr)
{
	int		index;

	index = 0;
	while (index < sol_nbr)
	{
		if (comb[index] == NULL)
			break ;
		if (comb[index]->id == ant->id)
			return (0);
		if (exclusive(comb[index]->path, ant->path) == 0)
			return (0);
		index++;
	}
	return (1);
}

int			calcul_cost(t_data *data, t_sol *solution, t_ant **comb)
{
	int		current_cost;
	int		index;
	int		nbr_path;

	current_cost = 0;
	index = 0;
	nbr_path = solution->nbr_path;
	while (index < solution->nbr_path)
	{
		if (comb[index] == NULL)
			break ;
		else
			current_cost += comb[index++]->length;
	}
	current_cost = (current_cost + data->ants_nbr - nbr_path) / nbr_path;
	return (current_cost);
}

void		replace_comb(t_data *data, t_sol *solution, t_ant **comb)
{
	int		index;

	index = 0;
	while (index < solution->nbr_path && index <= 15)
	{
		solution->ant[index] = comb[index];
		index++;
	}
	if (solution->cost < data->max_cost)
		data->max_cost = solution->cost;
}
