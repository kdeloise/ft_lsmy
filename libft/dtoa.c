/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:30:30 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/20 15:33:06 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_endf(t_flags *fl, char *str)
{
	if (fl->oc && fl->psn == 0)
	{
		write(1, ".", 1);
		fl->re += 1;
		fl->wdh -= 1;
	}
	if (fl->mi)
	{
		if (fl->wdh > (int)ft_strlen(str))
		{
			fl->wdh -= (int)ft_strlen(str);
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
	}
	free(str);
	str = NULL;
}

void		ft_bp(char *str, t_d *val, unsigned long long bp, long double ap)
{
	val->c--;
	if ((ap >= 0.5 && val->i == 0) || val->okr == 1)
	{
		str[val->c--] = (bp % 10) + '0' + 1;
		bp = bp / 10;
	}
	while (val->c >= 0)
	{
		str[val->c--] = (bp % 10) + '0';
		bp = bp / 10;
	}
}

long double	ft_ap(char *str, t_d *val, int p, long double ap)
{
	if (p > 0)
	{
		str[val->t++] = '.';
		while (p-- > 0)
		{
			ap = ap * 10.0;
			str[val->t++] = (char)ap + '0';
			ap = ap - (char)ap;
		}
		str[val->t--] = '\0';
		if (str[val->t] == '9' && ap >= 0.5)
		{
			while (str[val->t] == '9')
			{
				str[val->t--] = '0';
				if (str[val->t] == '.')
					val->okr = 1;
			}
		}
		if (ap >= 0.5 && str[val->t] != '.')
			str[val->t] = str[val->t] + 1;
	}
	else
		str[val->c] = '\0';
	return (ap);
}

int			nan_inf(double x, t_flags *fl)
{
	if (x != x)
	{
		write(1, "nan", 3);
		return (1);
	}
	if ((x == x + x / .0) && x > 0)
	{
		if (fl->pl)
		{
			write(1, "+inf", 4);
			return (1);
		}
		else
		{
			write(1, "inf", 3);
			return (1);
		}
	}
	if ((x == x + x / .0) && x < 0)
	{
		write(1, "-inf", 4);
		return (1);
	}
	return (0);
}

char		*ft_dtoa(t_flags *fl, long double x, int p)
{
	double				ap;
	unsigned long long	bp;
	char				*str;
	t_d					val;

	if (nan_inf(x, fl) == 1)
		return (NULL);
	val.f = ft_lastbit(x);
	val.okr = 0;
	val.c = lennbrf(x);
	(x > -1 && x < 1) ? val.c++ : 0;
	(x < 0 || val.f == 1) ? x = x * -1.0 : 0;
	bp = (unsigned long long)x;
	ap = x - bp;
	(p < 0) ? p = 6 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (val.c + p + 2))))
		return (NULL);
	val.t = val.c;
	val.i = p;
	ap = ft_ap(str, &val, p, ap);
	ft_bp(str, &val, bp, ap);
	(!fl->mi) ? ft_fflag(fl, str, val.f) : ft_fflagmi(fl, str, val.f);
	ft_putstr(str);
	ft_endf(fl, str);
	return (str);
}
