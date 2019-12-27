/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:01 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:02 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_colors2(char *s)
{
	if (!(ft_strcmp("{blue}", s)))
	{
		write(1, "\033[0;34m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{cyan}", s)))
	{
		write(1, "\033[0;36m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{gray}", s)))
	{
		write(1, "\033[0;37m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{eoc}", s)))
	{
		write(1, "\033[0m", 4);
		return (1);
	}
	return (0);
}

int	ft_colors(char *s)
{
	if (!(ft_strcmp("{magenda}", s)))
	{
		write(1, "\033[0;35m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{red}", s)))
	{
		write(1, "\033[0;31m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{green}", s)))
	{
		write(1, "\033[0;32m", 7);
		return (1);
	}
	else if (!(ft_strcmp("{yellow}", s)))
	{
		write(1, "\033[0;33m", 7);
		return (1);
	}
	else if (ft_colors2(s))
		return (1);
	return (0);
}

int	ft_color(const char *restrict fo)
{
	char	color[12];
	int		f;

	f = 0;
	ft_bzero(color, 12);
	while (fo[f])
	{
		color[f] = fo[f];
		if (fo[f] == '}')
		{
			f++;
			break ;
		}
		f++;
	}
	if (ft_colors(color))
		return (f);
	return (0);
}
