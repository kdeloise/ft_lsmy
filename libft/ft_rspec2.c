/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rspec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:41 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:42 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagstrr2(t_flags *fl, char *str, char **b)
{
	size_t	j;
	char	*tmp;

	j = 0;
	if (fl->psn > 0)
	{
		tmp = ft_strsub(str, 0, fl->psn);
		free(*b);
		*b = tmp;
		fl->wdh -= (int)(j = ft_strlen(*b));
		fl->re += (int)j;
	}
	else if (fl->psn == -1)
	{
		tmp = ft_strjoin(*b, str);
		free(*b);
		*b = tmp;
		fl->wdh -= (int)(j = ft_strlen(*b));
		fl->re += (int)j;
	}
}

void	ft_flagstrr3(char *b)
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
		}
		if (b[i] == '\0')
			break ;
		write(1, &b[i++], 1);
	}
}

void	ft_rspec3(t_flags *fl)
{
	if (fl->wdh > 0)
	{
		while (fl->wdh)
		{
			write(1, " ", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}

void	ft_rspec2(t_flags *fl)
{
	if (fl->psn == -1)
		ft_rspec3(fl);
	else if (fl->psn == 0)
	{
		while (fl->wdh)
		{
			write(1, " ", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	else
	{
		if (fl->wdh > 0)
		{
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
	}
}
