/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:08:52 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/17 14:28:33 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*n;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	n = (char *)malloc(sizeof(*s1) * len + 1);
	if (n == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		n[i] = s1[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
