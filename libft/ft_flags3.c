/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:59:19 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:20 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flagsoxx2(const char *fo, t_flags *fl)
{
	int f;

	f = 0;
	while (fo[f] != 'o' && fo[f] != 'x' && fo[f] != 'X' && fo[f] != '.'
			&& fo[f] != 'l' && fo[f] != 'h' && !(fo[f] >= 49 && fo[f] <= 57)
			&& fo[f] != '*')
	{
		if (fo[f] == '-')
		{
			if (!(fl->ze = 0))
				fl->mi = 1;
		}
		else if (fo[f] == '0')
			fl->ze = !(fl->mi) ? 1 : 0;
		else if (fo[f] == '#')
			fl->oc = 1;
		else
			return (-1);
		f++;
	}
	return (f);
}
