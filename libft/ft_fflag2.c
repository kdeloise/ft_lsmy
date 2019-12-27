/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:31 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:32 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftplf(char **buff, t_flags *fl, int num)
{
	char *tmp;

	if (!num)
	{
		tmp = ft_strjoin(*buff, "+");
		free(*buff);
		*buff = tmp;
		fl->wdh -= 1;
		fl->re += 1;
	}
	else
	{
		tmp = ft_strjoin(*buff, "-");
		free(*buff);
		*buff = tmp;
		fl->wdh -= 1;
		fl->re += 1;
	}
}

void	flwdhf(char **buff, t_flags *fl, int r)
{
	char *tmp;

	fl->wdh -= r;
	while (fl->wdh)
	{
		if (fl->ze)
		{
			tmp = ft_strjoin(*buff, "0");
			free(*buff);
			*buff = tmp;
		}
		else
		{
			tmp = ft_strjoin(" ", *buff);
			free(*buff);
			*buff = tmp;
		}
		fl->wdh -= 1;
		fl->re += 1;
	}
}

void	flspf(char **buff, t_flags *fl)
{
	char *tmp;

	tmp = ft_strjoin(*buff, " ");
	free(*buff);
	*buff = tmp;
	fl->wdh -= 1;
	fl->re += 1;
}

void	flplmif(t_flags *fl, int num)
{
	if (!num)
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

void	flnumf(char **buff, t_flags *fl)
{
	char *tmp;

	tmp = ft_strjoin(*buff, "-");
	free(*buff);
	*buff = tmp;
	fl->wdh -= 1;
	fl->re += 1;
}
