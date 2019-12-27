/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:22:03 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/19 20:22:04 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*n;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		n = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (n == 0)
			return (0);
		while (s[i] != '\0')
		{
			n[i] = f(s[i]);
			i++;
		}
		n[i] = '\0';
		return (n);
	}
	return (0);
}
