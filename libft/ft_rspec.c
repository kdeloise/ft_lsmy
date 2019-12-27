/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:36 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rpz(char *b, t_flags *fl)
{
	int i;

	i = 0;
	while (b[i] != '\0')
	{
		while (b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '\f'
				|| b[i] == '\r')
		{
			write(1, "\\", 1);
			if (b[i] == '\t')
				write(1, "t", 1);
			else if (b[i] == '\n')
				write(1, "n", 1);
			else if (b[i] == '\v')
				write(1, "v", 1);
			else if (b[i] == '\f')
				write(1, "f", 1);
			else if (b[i] == '\r')
				write(1, "r", 1);
			i++;
			fl->wdh -= 2;
			fl->re += 2;
		}
	}
}

void	ft_rp(int psn1, char *b, t_flags *fl)
{
	int i;

	i = 0;
	while (b[i] != '\0' && psn1)
	{
		while ((b[i] == '\t' || b[i] == '\n' || b[i] == '\v' || b[i] == '\f'
				|| b[i] == '\r') && psn1 > 0)
		{
			write(1, "\\", 1);
			if (b[i] == '\t')
				write(1, "t", 1);
			else if (b[i] == '\n')
				write(1, "n", 1);
			else if (b[i] == '\v')
				write(1, "v", 1);
			else if (b[i] == '\f')
				write(1, "f", 1);
			else if (b[i] == '\r')
				write(1, "r", 1);
			i++;
			psn1 -= 2;
			fl->wdh -= 2;
			fl->re += 2;
		}
	}
}

int		ft_flagstrmir(t_flags *fl, char *str)
{
	int i;
	int psn1;

	psn1 = fl->psn;
	i = 0;
	if (fl->mi)
	{
		if (psn1 > 0)
			ft_rp(psn1, str, fl);
		else if (psn1 == -1)
			ft_rpz(str, fl);
	}
	return (i);
}

void	ft_flagstrr(t_flags *fl, char *str)
{
	char	*b;
	char	*tmp;
	int		i;

	i = 0;
	b = (char *)malloc(sizeof(char));
	if (b == NULL)
		exit(-1);
	b[i] = '\0';
	ft_flagstrr2(fl, str, &b);
	if (fl->wdh > 0)
	{
		while (fl->wdh)
		{
			tmp = ft_strjoin(" ", b);
			free(b);
			b = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	ft_flagstrr3(b);
	free(b);
}

void	ft_rspec(t_args *ag, t_flags *fl)
{
	char	*str;
	int		s;

	str = va_arg(ag->args, char *);
	if (str == NULL)
		str = "(null)";
	if (!fl->mi)
		ft_flagstrr(fl, str);
	else
		s = ft_flagstrmir(fl, str);
	if (fl->mi)
		ft_rspec2(fl);
}
