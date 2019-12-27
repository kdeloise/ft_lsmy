/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:25:48 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/14 19:06:53 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	i = 0;
	if (len == 0)
		return (b);
	str = b;
	while (len != 0)
	{
		str[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
