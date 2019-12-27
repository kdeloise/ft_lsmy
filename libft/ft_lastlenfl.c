/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastlenfl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:31:21 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/20 15:31:23 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lennbrf(double x)
{
	int	i;

	i = 0;
	if (x < 0)
		x = x * -1.0;
	while (x >= 1)
	{
		x = x / 10.0;
		i++;
	}
	return (i);
}

int		ft_lastbit(double x)
{
	unsigned long		*ptr;

	ptr = (unsigned long *)&x;
	return (*ptr >> 63);
}
