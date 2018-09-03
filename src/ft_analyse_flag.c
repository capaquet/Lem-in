/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 08:30:00 by cpaquet           #+#    #+#             */
/*   Updated: 2018/04/24 09:36:54 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_analyse_flag(t_data *data, int argc, char **argv)
{
	int index;

	if (argc == 1)
		return (1);
	index = 1;
	while (index < argc)
	{
		if (ft_strequ(argv[index], "-info"))
			data->flag_info = 1;
		if (ft_strequ(argv[index], "-path"))
			data->flag_path = 1;
		if (ft_strequ(argv[index], "-ant"))
			data->flag_ant = 1;
		index++;
	}
	if (data->flag_info + data->flag_path + data->flag_ant != argc - 1)
	{
		ft_printf("Error Usage :\n");
		ft_printf("   -info: do not print rooms info.\n");
		ft_printf("   -path: print all possible paths identified.\n");
		ft_printf("   -ant: do not print ant movememts.\n\n");
		return (0);
	}
	return (1);
}
