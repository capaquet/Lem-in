/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:23:31 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 17:38:02 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	b;

	b = (char)c;
	if (c == '\0')
	{
		while (b != *s)
			s++;
		return ((char*)s);
	}
	while (b != *s && *s != '\0')
	{
		s++;
	}
	if (*s == '\0')
		return (0);
	else
		return ((char*)s);
}
