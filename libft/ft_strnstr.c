/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 02:16:09 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/17 14:40:35 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (len < len - (i + j))
			return (0);
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	return (0);
}
