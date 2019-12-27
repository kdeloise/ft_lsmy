/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pricont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:55 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:56 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pricont2(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	fl->lnh = 2;
	if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxx(fo, fl, ag));
	else
		return (-1);
	return (3);
}

int	ft_pricont(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	if (fo[l - 4] == 'l' || fo[l - 4] == 'h')
	{
		if (fo[l - 4] == 'l' && fo[l - 3] == 'l')
		{
			if ((ft_pricont2(fo, fl, l, ag)) == -1)
				return (-1);
			else
				return (0);
		}
		if (fo[l - 4] == 'h' && fo[l - 3] == 'h')
		{
			fl->lnh = 4;
			if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
				return (ft_flagsdi(fo, fl, ag));
			if (fo[l - 2] == 'u')
				return (ft_flagsu(fo, fl, ag));
			if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
				return (ft_flagsoxx(fo, fl, ag));
			else
				return (-1);
		}
		return (-1);
	}
	return (3);
}

int	ft_pricont3(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	fl->lnh = 3;
	if ((fo[l - 2] == 'd' || fo[l - 2] == 'i'))
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxx(fo, fl, ag));
	else
		return (-1);
}

int	ft_pricont4(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	fl->lnh = 1;
	if (fo[l - 2] == 'd' || fo[l - 2] == 'i')
		return (ft_flagsdi(fo, fl, ag));
	if (fo[l - 2] == 'u')
		return (ft_flagsu(fo, fl, ag));
	if (fo[l - 2] == 'o' || fo[l - 2] == 'x' || fo[l - 2] == 'X')
		return (ft_flagsoxx(fo, fl, ag));
	if (fo[l - 2] == 'f')
		return (ft_flagsf(fo, fl, ag));
	else
		return (-1);
}

int	ft_pricont5(const char *fo, t_flags *fl, unsigned long long l, t_args *ag)
{
	int t;

	if ((t = ft_pricont6(fo, fl, l, ag)) == -1)
		return (-1);
	else if (t == 0)
		return (0);
	if (fo[l - 3] == 'h')
	{
		if ((t = ft_pricont3(fo, fl, l, ag)) == -1)
			return (-1);
		else if (t == 3)
			;
		else if (t == 0)
			return (0);
	}
	if (fo[l - 3] == 'l')
	{
		if ((t = ft_pricont4(fo, fl, l, ag)) == -1)
			return (-1);
		else if (t == 3)
			;
		else if (t == 0)
			return (0);
	}
	return (0);
}
