/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:55:01 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:55:02 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh == 0)
		return (NULL);
	n = fresh;
	while (s[i] != s[start])
		i++;
	while (len && s[i])
	{
		*fresh = s[start];
		fresh++;
		start++;
		len--;
		i++;
	}
	*fresh = '\0';
	return (n);
}
