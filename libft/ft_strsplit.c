/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:59:37 by kdeloise          #+#    #+#             */
/*   Updated: 2019/04/22 16:59:38 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**n;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	n = (char **)malloc(sizeof(char *) * ft_cntword(s, c) + 1);
	if (n == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
			n[len++] = ft_strndup(&s[j], i - j);
	}
	n[len] = NULL;
	return (n);
}
