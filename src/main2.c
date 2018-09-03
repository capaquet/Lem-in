/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:54:47 by achirat           #+#    #+#             */
/*   Updated: 2018/04/24 09:58:17 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_ant_quick(int ants, char *name)
{
	int	a;

	a = 1;
	while (a <= ants)
	{
		ft_printf("L%d-%s", a, name);
		if (a != ants)
			ft_putchar(' ');
		a++;
	}
	ft_putchar('\n');
}

static void		printf_map(int flag, char **maps, int line)
{
	int		a;

	a = 0;
	if (flag == 0)
	{
		while (a < line)
			ft_printf("%s\n", maps[a++]);
		ft_printf("\n");
	}
}

static void		do_it(t_data *data)
{
	check_son(data);
	if (check_strend(data) == 1)
	{
		printf_map(data->flag_info, data->maps, data->line_map);
		print_ant_quick(data->ants_nbr, data->end_rooms->room_name);
	}
	else if (super_scoot(data) == 1)
	{
		printf_map(data->flag_info, data->maps, data->line_map);
		if (data->flag_ant == 0)
			distribute(data);
	}
	else
		ft_printf("ERROR\n");
}

int				main(int argc, char **argv)
{
	t_data	data;
	int		a;

	a = 0;
	ft_bzero(&data, sizeof(t_data));
	if (ft_analyse_flag(&data, argc, argv) == 0)
		return (0);
	if (get_info(&data) == -1)
		ft_printf("ERROR\n");
	else
		do_it(&data);
	ft_free1(&data);
	ft_free2(&data);
	return (0);
}
