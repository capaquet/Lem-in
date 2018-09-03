/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinatoire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:01:15 by achirat           #+#    #+#             */
/*   Updated: 2018/05/07 16:13:39 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_arrival(t_data *data, t_sol *solution, t_ant **comb)
{
	int		current_cost;

	current_cost = calcul_cost(data, solution, comb);
	if (solution->cost == 0 || current_cost < solution->cost)
	{
		solution->cost = current_cost;
		replace_comb(data, solution, comb);
	}
}

static	int		generate_comb(t_data *data, t_sol *solution,
														t_ant **comb, int index)
{
	t_list		*ant_tmp;

	ant_tmp = data->ant_sol;
	if (index == solution->nbr_path)
	{
		ft_arrival(data, solution, comb);
		return (1);
	}
	if (data->comb_limit++ >= 2500)
		return (1);
	while (ant_tmp)
	{
		if (verify_ant(comb, ant_tmp->content, solution->nbr_path) == 1)
			if (calcul_cost(data, solution, comb) <= data->max_cost)
			{
				comb[index] = ((t_ant *)ant_tmp->content);
				generate_comb(data, solution, comb, index + 1);
			}
		ant_tmp = ant_tmp->next;
	}
	return (0);
}

static void		best_comb(t_data *data, t_sol *solution, t_ant *ant)
{
	t_ant		*comb[solution->nbr_path];
	int			index;

	index = 0;
	while (index < solution->nbr_path)
		comb[index++] = NULL;
	comb[0] = ant;
	generate_comb(data, solution, comb, 1);
}

int				combinatoire(t_data *data, t_ant *ant)
{
	t_list		*solutions;
	int			count;

	count = 0;
	if (data->solution_list == NULL)
	{
		init_solution_list(data);
		return (1);
	}
	solutions = data->solution_list->next;
	while (solutions)
	{
		data->comb_limit = 0;
		if (((t_sol*)solutions->content)->nbr_path < data->len_ant_list)
			best_comb(data, solutions->content, ant);
		else
			break ;
		solutions = solutions->next;
	}
	return (1);
}
