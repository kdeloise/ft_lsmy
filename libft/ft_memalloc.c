/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:00:25 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/17 16:00:26 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *n;

	n = (void *)malloc(sizeof(void) * size);
	if (n == NULL)
		return (NULL);
	ft_bzero(n, size);
	return (n);
}
