/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:26 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:27 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fflag(t_flags *fl, char *s, int num)
{
	char	*buff;
	int		i;
	int		r;

	r = (int)ft_strlen(s);
	fl->re += r;
	i = 0;
	buff = (char *)malloc(sizeof(char));
	if (buff == NULL)
		exit(-1);
	buff[i] = '\0';
	if (fl->pl)
		ftplf(&buff, fl, num);
	else if (fl->sp && !num)
		flspf(&buff, fl);
	if (num && !fl->pl)
		flnumf(&buff, fl);
	if (fl->wdh > r)
		flwdhf(&buff, fl, r);
	while (buff[i] != '\0')
		write(1, &buff[i++], 1);
	free(buff);
}

void	ft_fflagmi(t_flags *fl, char *s, int num)
{
	fl->re += (int)ft_strlen(s);
	if (fl->mi)
	{
		if (fl->pl)
			flplmif(fl, num);
		else if (fl->sp && !num)
		{
			write(1, " ", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
		if (num && !fl->pl)
		{
			write(1, "-", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
}
