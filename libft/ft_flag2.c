/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:52 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:53 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagmi2(t_flags *fl, long long int num)
{
	if (fl->pl)
	{
		if (num >= 0)
		{
			write(1, "+", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
		else
		{
			write(1, "-", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	else if (fl->sp && num >= 0)
	{
		write(1, " ", 1);
		fl->wdh -= 1;
		fl->re += 1;
	}
}

void	ft_flagmi3(t_flags *fl, int r)
{
	if (r < fl->psn)
	{
		fl->psn -= r;
		while (fl->psn)
		{
			write(1, "0", 1);
			fl->psn -= 1;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}

void	nump(char **buff, t_flags *fl)
{
	char *tmp;

	tmp = ft_strjoin(*buff, "+");
	free(*buff);
	*buff = tmp;
	fl->wdh -= 1;
	fl->re += 1;
}

void	ft_flag2(char **buff, t_flags *fl, long long int num)
{
	char *tmp;

	if (fl->pl)
	{
		if (num >= 0)
			nump(buff, fl);
		else
		{
			tmp = ft_strjoin(*buff, "-");
			free(*buff);
			*buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	else if (fl->sp && num >= 0)
	{
		tmp = ft_strjoin(*buff, " ");
		free(*buff);
		*buff = tmp;
		fl->wdh -= 1;
		fl->re += 1;
	}
}

void	ft_flag3(char **buff, t_flags *fl, int r)
{
	char *tmp;

	if (!fl->nn)
		fl->wdh -= r;
	while (fl->wdh)
	{
		if (fl->ze)
		{
			tmp = ft_strjoin(*buff, "0");
			free(*buff);
			*buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
		else
		{
			tmp = ft_strjoin(" ", *buff);
			free(*buff);
			*buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}
