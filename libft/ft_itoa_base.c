/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:31:07 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/20 15:31:15 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_flmi(int r, t_flags *fl)
{
	if (fl->wdh > r)
	{
		if (!fl->nn)
			fl->wdh -= r;
		while (fl->wdh)
		{
			write(1, " ", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}

void	ft_isptr(char *t, t_flags *fl)
{
	t[0] = '0';
	t[1] = 'x';
	if (fl->psn == 0)
	{
		t[2] = '\0';
		fl->nn = 0;
		fl->re += 2;
	}
}

void	ft_end(char *t, t_flags *fl, int r)
{
	(fl->isptr) ? ft_isptr(t, fl) : 0;
	(!fl->nn) ? ft_putstr(t) : 0;
	(fl->mi) ? ft_flmi(r, fl) : 0;
	free(t);
}

int		ft_setlennbr(long long int n, int x, int sz, t_flags *fl)
{
	int	i;

	i = (n > 0 && x == 10) ? ft_lennbr_base(n, x) : ft_lennbr_base(n, x);
	if (x == 8 || x == 16 || fl->unsign)
	{
		if (sz == 1)
			i = ft_lennbr_base_ch(n, x);
		else if (sz == 2)
			i = ft_lennbr_base_sh(n, x);
		else if (sz == 4)
			i = ft_lennbr_base_ui(n, x);
		else if (sz == 8)
			i = ft_lennbr_base_ull(n, x);
	}
	if (fl->isptr && n >= 0)
		i = ft_lennbr_base(n, x) + 2;
	else if (fl->isptr && n < 0)
		i = ft_lennbr_base_ull(n, x) + 2;
	return (i);
}

char	*ft_itoa_base(t_flags *fl, long long int n, int sz, char *base)
{
	int						i;
	unsigned long long int	nbr;
	char					*t;
	int						x;
	int						r;

	x = ft_strlen(base);
	i = ft_setlennbr(n, x, sz, fl);
	(n == 0 && (fl->xox == 1 || fl->xox == 3)) ? fl->oc = 0 : 0;
	(!(fl->psn == 0 && n == 0)) ? fl->re += i : 0;
	r = i;
	(!fl->mi) ? ft_flag(fl, n, i) : ft_flagmi(fl, n, i);
	if (!(t = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	t[i--] = '\0';
	nbr = (n < 0 && x == 10) ? (n * -1) : n;
	if (n < 0 && (x == 16 || x == 8 || fl->unsign || fl->isptr))
		nbr = (unsigned long long int)n;
	while (i >= 0)
	{
		t[i--] = base[nbr % x];
		nbr = nbr / x;
	}
	ft_end(t, fl, r);
	return (NULL);
}
