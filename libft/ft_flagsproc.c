/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsproc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:25 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:25 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagsproc2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != '%' && fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57))
	{
		if (fo[f] == '-')
		{
			if (!(fl->ze = 0))
				fl->mi = 1;
		}
		else if (fo[f] == '+' || fo[f] == ' ' || fo[f] == '#')
			;
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else
			return (-1);
		f++;
	}
	return (f);
}

int	ft_flagsproc(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = ft_flagsproc2(fo, fl)) == -1)
		return (-1);
	if (fo[f] >= 48 && fo[f] <= 57)
	{
		ft_wdh(fo + f, fl, ag);
		while (fo[f] >= 48 && fo[f] <= 57)
			f++;
	}
	if (fo[f] == '.')
	{
		ft_psn(fo + f, fl, ag);
		f++;
		while (fo[f] >= 48 && fo[f] <= 57)
			f++;
	}
	if (fo[f] != '%')
		return (-1);
	return (1);
}
