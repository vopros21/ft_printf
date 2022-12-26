/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022-12-26 21:42:09 by mkostenk          #+#    #+#             */
/*   Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_checkformat(char *str, va_list args)
{
	int		len;
	char	frmt;

	len = 0;
	frmt = *str;
	if (frmt == '%')
	{
		write(1, "%", 1);
		len += 1;
	}
	else if (frmt == 'c')
		len += ft_printchar(args);
	else if (frmt == 's')
		len += ft_printstr(args);
	else if (frmt == 'p')
		len += ft_printptr(args);
	else if (frmt == 'i' || frmt == 'd')
		len += ft_printint(args);
	else if (frmt == 'u')
		len += ft_printuns(args);
	else if (frmt == 'x' || frmt == 'X')
		len += ft_printhex(args, frmt);
	return (len);
}
