/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pricont2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:01 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:02 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pricont6(const char *fo, t_flags *fl, unsigned long long l,
		t_args *ag)
{
	int t;

	if (fo[l - 3] == 'L')
	{
		if (fo[l - 2] == 'f')
		{
			fl->lnh = 5;
			return (ft_flagsf(fo, fl, ag));
		}
		else
			return (-1);
	}
	if (!(l - 3 == 0))
	{
		if ((t = ft_pricont(fo, fl, l, ag)) == -1)
			return (-1);
		else if (t == 3)
			;
		else if (t == 0)
			return (0);
	}
	return (3);
}

int		ft_spec2(const char *fo, t_args *ag, t_flags *fl)
{
	int f;

	f = 1;
	ag->len = 2;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' &&
	fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] != 'X' &&
	fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0' && fo[f] != '%' &&
	fo[f] != 'r')
	{
		ag->len += 1;
		f++;
	}
	f = 1;
	while (fo[f] != 'c' && fo[f] != 'd' && fo[f] != 'i' && fo[f] != 'p' &&
	fo[f] != 'o' && fo[f] != 'u' && fo[f] != 'x' && fo[f] != 'X' &&
	fo[f] != 'f' && fo[f] != 's' && fo[f] != '\0' && fo[f] != '%' &&
	fo[f] != 'r')
	{
		if (ft_flags(fo + f, fl, ag->len, ag) == -1)
			return (-1);
		f += (ag->len - 2);
	}
	return (f);
}

void	ft_spec3(const char *fo, t_args *ag, t_flags *fl, int f)
{
	if (fo[f] == 'd' || fo[f] == 'i')
		ft_dispec(ag, fl);
	else if (fo[f] == 'u')
		ft_uspec(ag, fl);
	else if (fo[f] == 'p')
		ft_pspec(ag, fl);
	else if (fo[f] == 'x' || fo[f] == 'X' || fo[f] == 'o')
		ft_xoxspec(ag, fl, fo + f);
	else if (fo[f] == 'c')
		ft_cspec(ag, fl);
	else if (fo[f] == 'f')
		ft_fspec(ag, fl);
	else if (fo[f] == '%')
		ft_procspec(fl);
	else if (fo[f] == 's')
		ft_sspec(ag, fl);
	else if (fo[f] == 'r')
		ft_rspec(ag, fl);
	else if (fo[f - 1] == '%')
		ag->len -= 1;
}

int		ft_printf2(const char *format, t_flags *fl, t_args *ag, int f)
{
	t_err	err;

	fl = ft_filltf(fl);
	if ((err.errf = ft_spec(format, ag, fl)) == 0)
	{
		write(1, "%", 1);
		fl->re += 1;
		f += 2;
	}
	else if (err.errf == -1)
	{
		write(1, "Wrong flag with this conversion specifier\n", 42);
		return (0);
	}
	else
		f += ag->len;
	return (f);
}
