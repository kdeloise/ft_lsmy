/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 23:47:11 by kdeloise          #+#    #+#             */
/*   Updated: 2019/10/26 04:57:48 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lennbr(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
