/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:37 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*ft_filltf(t_flags *fl)
{
	fl->mi = 0;
	fl->pl = 0;
	fl->ze = 0;
	fl->oc = 0;
	fl->sp = 0;
	fl->wdh = 0;
	fl->psn = -1;
	fl->lnh = 0;
	fl->nn = 0;
	fl->xox = 0;
	fl->isxox = 0;
	fl->unsign = 0;
	fl->isptr = 0;
	return (fl);
}

void		ft_psnb(t_flags *fl, const char *fo)
{
	int		f;
	int		i;
	char	buff[11];

	i = 0;
	f = 1;
	while (fo[f] >= 48 && fo[f] <= 57)
	{
		buff[i] = fo[f];
		i++;
		f++;
	}
	buff[i] = '\0';
	fl->psn = ft_atoi(buff);
}

void		ft_wdh(const char *fo, t_flags *fl, t_args *ag)
{
	char	buff[11];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (fo[i] == '*' && !(fo[i + 1] >= 48 && fo[i + 1] <= 57))
	{
		fl->wdh = va_arg(ag->args, int);
		if (fl->wdh < 0 && (fl->mi = 1))
			fl->wdh *= -1;
	}
	else
	{
		if (fo[i] == '*')
		{
			va_arg(ag->args, int);
			i++;
		}
		while (fo[i] >= 48 && fo[i] <= 57)
			buff[j++] = fo[i++];
		buff[i] = '\0';
		fl->wdh = ft_atoi(buff);
	}
}

int			ft_psn(const char *fo, t_flags *fl, t_args *ag)
{
	int		f;

	f = 1;
	if (!(fo[f] >= 48 && fo[f] <= 57) && fo[f] != '*')
	{
		fl->psn = 0;
		return (0);
	}
	else
	{
		if (fo[f] == '*')
		{
			fl->psn = va_arg(ag->args, int);
			if (fl->psn < 0 && fo[f + 1] == 's')
				fl->psn *= -1;
		}
		else
			ft_psnb(fl, fo);
	}
	return (1);
}
