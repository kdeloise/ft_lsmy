/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:13 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:14 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flagsdi2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'l' && fo[f] != 'h'
			&& fo[f] != '.' && !(fo[f] >= 49 && fo[f] <= 57) && fo[f] != '*')
	{
		if (fo[f] == '-' && !(fl->ze = 0))
			fl->mi = 1;
		else if (fo[f] == '+')
		{
			if (!(fl->sp = 0))
				fl->pl = 1;
		}
		else if (fo[f] == ' ')
			fl->sp = (!(fl->pl)) ? 1 : 0;
		else if (fo[f] == '0')
		{
			if (!(fl->mi))
				fl->ze = 1;
		}
		else
			return (-1);
		f++;
	}
	return (f);
}

int	flagscsp2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'c' && fo[f] != 's' && fo[f] != 'p' && fo[f] != '.'
			&& !(fo[f] >= 49 && fo[f] <= 57) && fo[f] != '*' && fo[f] != 'r')
	{
		if (fo[f] == '-')
			fl->mi = 1;
		else if (fo[f] == ' ' || fo[f] == '#')
			;
		else
			return (-1);
		f++;
	}
	return (f);
}

int	flagsf3(const char *fo, t_flags *fl, int f)
{
	if (fo[f] == '-')
	{
		if (!(fl->ze = 0))
			fl->mi = 1;
	}
	else if (fo[f] == '+')
	{
		if (!(fl->sp = 0))
			fl->pl = 1;
	}
	else if (fo[f] == ' ')
		fl->sp = !(fl->pl) ? 1 : 0;
	else if (fo[f] == '0')
		fl->ze = !(fl->mi) ? 1 : 0;
	else if (fo[f] == '#')
		fl->oc = 1;
	else
		return (-1);
	return (0);
}

int	flagsf2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'f' && fo[f] != '.' && fo[f] != 'l' && fo[f] != 'L' &&
			!(fo[f] >= 49 && fo[f] <= 57) && fo[f] != '*')
	{
		if (flagsf3(fo, fl, f) == -1)
			return (-1);
		f++;
	}
	return (f);
}

int	ft_flagsu2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'u' && fo[f] != '.' && fo[f] != 'l' && fo[f] != 'h'
			&& !(fo[f] >= 49 && fo[f] <= 57) && fo[f] != '*')
	{
		if (fo[f] == '-')
		{
			if (!(fl->ze = 0))
				fl->mi = 1;
		}
		else if (fo[f] == '0')
		{
			if ((!fl->mi))
				fl->ze = 1;
		}
		else if (fo[f] == ' ' || fo[f] == '+')
			;
		else
			return (-1);
		f++;
	}
	return (f);
}
