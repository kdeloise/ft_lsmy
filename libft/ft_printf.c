/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:11 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:12 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	if (!(l - 2 == 0))
		if (fo[l - 2] == '%')
			return (ft_flagsproc(fo, fl, ag));
	if (fo[l - 3] == 'l' || fo[l - 3] == 'h' || fo[l - 3] == 'L')
	{
		if ((ft_pricont5(fo, fl, l, ag) == -1))
			return (-1);
		else
			return (0);
	}
	if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxx(fo, fl, ag));
	if (fo[l - 2] == 'f')
		return (ft_flagsf(fo, fl, ag));
	if (fo[l - 2] == 'c' || fo[l - 2] == 's' || fo[l - 2] == 'p' ||
			fo[l - 2] == 'r')
		return (ft_flagscsp(fo, fl, ag));
	return (-1);
}

int	ft_spec(const char *fo, t_args *ag, t_flags *fl)
{
	int f;

	if (fo[1] == '%')
		return (0);
	if ((f = ft_spec2(fo, ag, fl)) == -1)
		return (-1);
	ft_spec3(fo, ag, fl, f);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_args	ag;
	t_flags	fl;
	int		c;

	va_start(ag.args, format);
	fl.f = 0;
	fl.re = 0;
	while (format[fl.f])
	{
		while (format[fl.f] == '{')
		{
			((c = ft_color(format + fl.f)) != 0) ? fl.f += c : 0;
			if (c == 0)
				break ;
		}
		while (format[fl.f] == '%')
			if ((fl.f = ft_printf2(format + fl.f, &fl, &ag, fl.f)) == 0)
				return (0);
		if (!format[fl.f])
			break ;
		write(1, &format[fl.f++], 1);
		fl.re += 1;
	}
	va_end(ag.args);
	return (fl.re);
}
