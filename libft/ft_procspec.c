/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:26 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:27 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_procspec(t_flags *fl)
{
	if (!fl->mi)
	{
		ft_flag(fl, 1, 1);
		write(1, "%", 1);
		fl->re += 1;
	}
	else
	{
		ft_flagmi(fl, 1, 1);
		write(1, "%", 1);
		fl->re += 1;
	}
	if (fl->mi)
	{
		if (fl->wdh > 1)
		{
			fl->wdh -= 1;
			while (fl->wdh)
			{
				write(1, " ", 1);
				fl->wdh -= 1;
				fl->re += 1;
			}
		}
	}
}

void	ft_flagstr(t_flags *fl, char *str)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = 0;
	buff = (char *)malloc(sizeof(char));
	if (buff == NULL)
		exit(-1);
	buff[i] = '\0';
	ft_flagstr2(fl, str, &buff);
	if (fl->wdh > 0)
	{
		while (fl->wdh)
		{
			tmp = ft_strjoin(" ", buff);
			free(buff);
			buff = tmp;
			fl->wdh -= 1;
			fl->re += 1;
		}
	}
	while (buff[i] != '\0')
		write(1, &buff[i++], 1);
	free(buff);
}

int		ft_flagstrmi2(t_flags *fl, char *str, int psn1)
{
	int i;

	i = 0;
	while (psn1 && str[i])
	{
		write(1, &str[i], 1);
		psn1 -= 1;
		fl->wdh -= 1;
		fl->re += 1;
		i++;
	}
	return (i);
}

int		ft_flagstrmi(t_flags *fl, char *str)
{
	int i;
	int psn1;

	psn1 = fl->psn;
	i = 0;
	if (fl->mi)
	{
		if (psn1 > 0)
			i += ft_flagstrmi2(fl, str, psn1);
		else if (psn1 == -1)
		{
			while (str[i])
			{
				write(1, &str[i], 1);
				fl->wdh -= 1;
				fl->re += 1;
				i++;
			}
		}
	}
	return (i);
}
