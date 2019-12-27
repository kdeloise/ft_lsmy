/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:05:37 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/20 20:05:38 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*n;
	unsigned int	i;
	unsigned int	len;
	unsigned int	sn;

	if (s)
	{
		i = 0;
		sn = 0;
		len = ft_strlen(s) - 1;
		if (s[i] == '\0')
			return ((char *)s + i);
		while (s[sn] == ' ' || s[sn] == '\t' || s[sn] == '\n')
			sn++;
		while (len > 0 && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n'))
			len--;
		n = (char *)malloc(sizeof(char) * (len - (sn - 1) + 1));
		if (n == 0)
			return (0);
		while (len >= sn)
			n[i++] = s[sn++];
		n[i] = '\0';
		return (n);
	}
	return (0);
}
