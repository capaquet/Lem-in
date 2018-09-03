/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:54:16 by achirat           #+#    #+#             */
/*   Updated: 2018/04/24 09:18:39 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_line(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(line, "##start") == 1 &&
		ft_strcmp(line, "##end") == 1)
		return (0);
	return (1);
}
