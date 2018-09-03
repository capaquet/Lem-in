/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:53:12 by achirat           #+#    #+#             */
/*   Updated: 2018/05/08 11:21:25 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_name_tube(char **tab, t_data *data)
{
	t_list	*room;
	int		a;

	a = 0;
	room = data->head_rooms;
	while (room)
	{
		if (ft_strequ(((t_coord*)room->content)->room_name, tab[0]) == 1)
			a++;
		if (ft_strequ(((t_coord*)room->content)->room_name, tab[1]) == 1)
			a++;
		if (a == 2)
			return (1);
		room = room->next;
	}
	return (0);
}

int		check_is_digit(char **tab)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (tab[1][a] || tab[2][b])
	{
		if ((tab[1][a] != '\0' && ft_isdigit(tab[1][a]) == 0) ||
			(tab[2][b] != '\0' && ft_isdigit(tab[2][b]) == 0))
			return (0);
		if (tab[1][a] != '\0')
			a++;
		if (tab[2][b] != '\0')
			b++;
	}
	return (1);
}
