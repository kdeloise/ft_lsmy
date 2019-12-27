/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:25:54 by kdeloise          #+#    #+#             */
/*   Updated: 2019/10/26 04:59:02 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strnew(size_t size)
{
	char *n;

	n = (char *)malloc(sizeof(char) * size + 1);
	if (n == NULL)
		return (NULL);
	ft_bzero(n, size + 1);
	return (n);
}
