/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:31:35 by kdeloise          #+#    #+#             */
/*   Updated: 2019/09/20 15:31:36 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lnh3(t_flags *fl, t_args *ag, const char *fo)
{
	if (fo[0] == 'x')
		return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int),
		2, "0123456789abcdef"));
	else if (fo[0] == 'o')
		return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int),
		2, "01234567"));
	else if (fo[0] == 'X')
		return (ft_itoa_base(fl, (unsigned short)va_arg(ag->args, unsigned int),
		2, "0123456789ABCDEF"));
		return (0);
}

char	*ft_lnh4(t_flags *fl, t_args *ag, const char *fo)
{
	if (fo[0] == 'x')
		return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int),
		1, "0123456789abcdef"));
	else if (fo[0] == 'o')
		return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int),
		1, "01234567"));
	else if (fo[0] == 'X')
		return (ft_itoa_base(fl, (unsigned char)va_arg(ag->args, unsigned int),
		1, "0123456789ABCDEF"));
		return (0);
}

char	*ft_lnh1(t_flags *fl, t_args *ag, const char *fo)
{
	if (fo[0] == 'x')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int),
		8, "0123456789abcdef"));
	else if (fo[0] == 'o')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int),
		8, "01234567"));
	else if (fo[0] == 'X')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long int),
		8, "0123456789ABCDEF"));
		return (0);
}

char	*ft_lnh2(t_flags *fl, t_args *ag, const char *fo)
{
	if (fo[0] == 'x')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int),
		8, "0123456789abcdef"));
	else if (fo[0] == 'o')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int),
		8, "01234567"));
	else if (fo[0] == 'X')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned long long int),
		8, "0123456789ABCDEF"));
		return (0);
}

char	*ft_lnh0(t_flags *fl, t_args *ag, const char *fo)
{
	if (fo[0] == 'x')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned int),
		4, "0123456789abcdef"));
	else if (fo[0] == 'o')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned int),
		4, "01234567"));
	else if (fo[0] == 'X')
		return (ft_itoa_base(fl, va_arg(ag->args, unsigned int),
		4, "0123456789ABCDEF"));
		return (0);
}
