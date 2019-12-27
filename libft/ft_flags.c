/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagsdi(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = flagsdi2(fo, fl)) == -1)
		return (-1);
	if ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
	{
		ft_wdh(fo + f, fl, ag);
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] == '.')
	{
		if (fo[f + 1] != '*')
			fl->ze = 0;
		ft_psn(fo + f, fl, ag);
		f++;
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'l' && fo[f] != 'h')
		return (-1);
	return (0);
}

int	ft_flagscsp(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = flagscsp2(fo, fl)) == -1)
		return (-1);
	if ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
	{
		ft_wdh(fo + f, fl, ag);
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] == '.')
	{
		ft_psn(fo + f, fl, ag);
		f++;
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
		if (fo[f] == 'c')
			fl->psn = -1;
		if (fo[f] == 'p')
			fl->psn = (fl->psn == 0) ? 0 : -1;
	}
	if (fo[f] != 'c' && fo[f] != 's' && fo[f] != 'p' && fo[f] != 'r')
		return (-1);
	return (1);
}

int	ft_flagsf(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = flagsf2(fo, fl)) == -1)
		return (-1);
	if ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
	{
		ft_wdh(fo + f, fl, ag);
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] == '.')
	{
		ft_psn(fo + f, fl, ag);
		f++;
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] != 'f' && fo[f] != 'l' && fo[f] != 'L')
		return (-1);
	return (0);
}

int	ft_flagsu(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = ft_flagsu2(fo, fl)) == -1)
		return (-1);
	if ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
	{
		ft_wdh(fo + f, fl, ag);
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] == '.')
	{
		if (fo[f + 1] != '*')
			fl->ze = 0;
		ft_psn(fo + f, fl, ag);
		f++;
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] != 'u' && fo[f] != 'l' && fo[f] != 'h')
		return (-1);
	return (0);
}

int	ft_flagsoxx(const char *fo, t_flags *fl, t_args *ag)
{
	int f;

	if ((f = ft_flagsoxx2(fo, fl)) == -1)
		return (-1);
	if ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
	{
		ft_wdh(fo + f, fl, ag);
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] == '.')
	{
		if (fo[f + 1] != '*')
			fl->ze = 0;
		ft_psn(fo + f, fl, ag);
		f++;
		while ((fo[f] >= 48 && fo[f] <= 57) || fo[f] == '*')
			f++;
	}
	if (fo[f] != 'o' && fo[f] != 'x' && fo[f] != 'X' && fo[f] != 'h' &&
			fo[f] != 'l')
		return (-1);
	return (0);
}
