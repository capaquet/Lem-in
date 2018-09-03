/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:27:54 by achirat           #+#    #+#             */
/*   Updated: 2018/04/23 19:32:32 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_strend(t_data *data)
{
	int		a;

	a = 0;
	while (a < data->start_rooms->nbr_sons)
	{
		if (data->start_rooms->sons[a]->position == 2)
			return (1);
		a++;
	}
	return (0);
}
