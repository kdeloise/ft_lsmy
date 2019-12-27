/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:58 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:58 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag4(char **buff, t_flags *fl, int r)
{
	char *tmp;

	if (r < fl->psn)
	{
		fl->psn -= r;
		while (fl->psn)
		{
			tmp = ft_strjoin(*buff, "0");
			free(*buff);
			*buff = tmp;
			fl->psn -= 1;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}

void	ft_flag5(char **buff, t_flags *fl)
{
	char *tmp;

	tmp = ft_strjoin(*buff, "-");
	free(*buff);
	*buff = tmp;
	fl->wdh -= 1;
	fl->re += 1;
}
