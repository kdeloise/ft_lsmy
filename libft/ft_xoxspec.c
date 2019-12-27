/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoxspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:54 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:55 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xoxspec(t_args *ag, t_flags *fl, const char *fo)
{
	fl->isxox = 1;
	if (fo[0] == 'x')
		fl->xox = 1;
	else if (fo[0] == 'o')
		fl->xox = 2;
	else if (fo[0] == 'X')
		fl->xox = 3;
	if (!fl->lnh)
		return (ft_lnh0(fl, ag, fo));
	else if (fl->lnh == 2)
		return (ft_lnh2(fl, ag, fo));
	else if (fl->lnh == 1)
		return (ft_lnh1(fl, ag, fo));
	else if (fl->lnh == 4)
		return (ft_lnh4(fl, ag, fo));
	else if (fl->lnh == 3)
		return (ft_lnh3(fl, ag, fo));
	return (0);
}

void	ft_oct(t_flags *fl, char **buff, char *tmp)
{
	if (fl->xox == 1)
	{
		tmp = ft_strjoin("0x", *buff);
		free(*buff);
		*buff = tmp;
		fl->wdh -= 2;
		fl->re += 2;
	}
	else if (fl->xox == 2)
	{
		tmp = ft_strjoin("0", *buff);
		free(*buff);
		*buff = tmp;
		fl->wdh -= 1;
		fl->re += 1;
	}
	else if (fl->xox == 3)
	{
		tmp = ft_strjoin("0X", *buff);
		free(*buff);
		*buff = tmp;
		fl->wdh -= 2;
		fl->re += 2;
	}
}

void	ft_octmi(t_flags *fl)
{
	if (fl->xox == 1)
	{
		write(1, "0x", 2);
		fl->wdh -= 2;
		fl->re += 2;
	}
	else if (fl->xox == 2)
	{
		write(1, "0", 1);
		fl->wdh -= 1;
		fl->re += 1;
	}
	else if (fl->xox == 3)
	{
		write(1, "0X", 2);
		fl->wdh -= 2;
		fl->re += 2;
	}
}
