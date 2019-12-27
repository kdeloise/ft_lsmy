/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:00:46 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/24 18:00:47 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uspec(t_args *ag, t_flags *fl)
{
	fl->unsign = 1;
	if (!fl->lnh)
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned int),
		4, "0123456789"));
	else if (fl->lnh == 2)
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int),
		8, "0123456789"));
	else if (fl->lnh == 1)
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int),
		8, "0123456789"));
	else if (fl->lnh == 4)
		return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int),
		1, "0123456789"));
	else if (fl->lnh == 3)
		return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int),
		2, "0123456789"));
		return (0);
}

char	*ft_pspec(t_args *ag, t_flags *fl)
{
	fl->isptr = 1;
	return (ft_itoa_base(fl, va_arg(ag->args, long long int),
	8, "0123456789abcdef"));
}
