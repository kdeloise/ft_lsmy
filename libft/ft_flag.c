/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:48 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 17:58:49 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagmi(t_flags *fl, long long int num, int r)
{
	if (fl->mi)
	{
		ft_flagmi2(fl, num);
		if (num < 0 && !fl->pl && !fl->isxox && !fl->unsign && !fl->isptr)
		{
			write(1, "-", 1);
			fl->wdh -= 1;
			fl->re += 1;
		}
		if (num == 0 && fl->psn == 0)
			fl->nn = 1;
		if (fl->xox == 2 && fl->psn > ft_lennbr_base_ull(num, 8))
			fl->oc = 0;
		if (num == 0 && fl->xox == 2 && fl->psn != 0)
			fl->oc = 0;
		if (fl->oc)
			ft_octmi(fl);
		if (fl->psn > 0)
			ft_flagmi3(fl, r);
	}
}

void	ft_flag(t_flags *fl, long long int num, int r)
{
	char	*buff;
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	if (!(buff = (char *)malloc(sizeof(char))))
		exit(-1);
	buff[i] = '\0';
	ft_flag2(&buff, fl, num);
	if (num < 0 && !fl->pl && !fl->isxox && !fl->unsign && !fl->isptr)
		ft_flag5(&buff, fl);
	fl->nn = (num == 0 && fl->psn == 0) ? 1 : 0;
	if (fl->xox == 2 && fl->psn > ft_lennbr_base_ull(num, 8))
		fl->oc = 0;
	(num == 0 && fl->xox == 2 && fl->psn != 0) ? fl->oc = 0 : 0;
	if (fl->oc)
		ft_oct(fl, &buff, tmp);
	if (fl->psn > 0)
		ft_flag4(&buff, fl, r);
	if (fl->wdh > r)
		ft_flag3(&buff, fl, r);
	while (buff[i] != '\0')
		write(1, &buff[i++], 1);
	free(buff);
}
