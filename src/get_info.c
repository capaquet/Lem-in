/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:38:04 by achirat           #+#    #+#             */
/*   Updated: 2018/05/08 11:11:54 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_rooms(t_data *data, char **tab, int *pos)
{
	t_coord		coord;
	t_list		*new;

	ft_bzero(&coord, sizeof(t_coord));
	coord.x = ft_atoi(tab[1]);
	coord.y = ft_atoi(tab[2]);
	if (coord.x < 0 || coord.y < 0)
		return ;
	if (check_room_dup(data->head_rooms, &coord, tab[0]) == 1 ||
		check_roomcoord(data->head_rooms, &coord, tab[0]) == -1)
		return ;
	coord.room_name = ft_strdup(tab[0]);
	coord.position = *pos;
	if (!(new = ft_lstnew(&coord, sizeof(t_coord))))
		exit(EXIT_FAILURE);
	ft_lstadd(&data->head_rooms, new);
	data->rooms_nbrs++;
	*pos = 0;
}

static void		ft_tubes(t_data *data, char **tab)
{
	t_tube	tube;
	t_list	*new;

	ft_bzero(&tube, sizeof(t_tube));
	tube.name_1 = ft_strdup(tab[0]);
	tube.name_2 = ft_strdup(tab[1]);
	if (!(new = ft_lstnew(&tube, sizeof(t_tube))))
		exit(EXIT_FAILURE);
	ft_lstadd(&data->head_tubes, new);
}

static int		sort(char *line, t_data *data, int *position)
{
	char	**tab;
	int		data_type;
	char	a;

	data_type = 0;
	a = ' ';
	(ft_strchr(line, '-') ? a = '-' : a);
	tab = ft_strsplit(line, a);
	while (tab[data_type])
		data_type++;
	if (*position == 0 && data_type == 1 && a == ' ' && check_line_info(line) &&
		data->ants_nbr == 0)
		data->ants_nbr = ft_atoi(tab[0]);
	else if (data_type == 3 && a == ' ' && (ft_isalpha(tab[1][0]) == 0 ||
			ft_isalpha(tab[2][0]) == 0) && check_is_digit(tab))
		ft_rooms(data, tab, position);
	else if (*position == 0 && data_type == 2 && a == '-' &&
			ft_strequ(tab[0], tab[1]) == 0 && check_name_tube(tab, data) == 1)
		ft_tubes(data, tab);
	else
		return (free_double_tab(&tab, 0));
	return (free_double_tab(&tab, 1));
}

static void		ft_save_info(t_data *data, char *line)
{
	char	**tmp;
	int		a;

	a = 0;
	data->line_map++;
	if (!(tmp = (char**)malloc(sizeof(char*) * data->line_map)))
		exit(EXIT_FAILURE);
	while (data->maps && a < data->line_map - 1)
	{
		tmp[a] = data->maps[a];
		a++;
	}
	tmp[a] = ft_strdup(line);
	free(data->maps);
	data->maps = tmp;
	tmp = NULL;
}

int				get_info(t_data *data)
{
	char	*line;
	int		position;

	position = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "##start") == 0)
			position = 1;
		else if (ft_strcmp(line, "##end") == 0)
			position = 2;
		else if ((line[0] == '#' && line[1] != '#') || (line[0] == '#' &&
				line[1] == '#' && line[2] != '#'))
			;
		else if (sort(line, data, &position) == 0)
		{
			ft_strdel(&line);
			break ;
		}
		if (data->flag_info == 0)
			ft_save_info(data, line);
		ft_strdel(&line);
	}
	return ((ft_check_coord(data) == -1 || check_data(data) == -1 ||
		search_start_end(data) == 0) ? -1 : 1);
}
