/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:02:00 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/22 19:02:01 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*t;
	size_t	i;

	t = (char *)malloc(sizeof(*s1) * n + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
